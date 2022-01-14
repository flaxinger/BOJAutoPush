#include <bits/stdc++.h>

using namespace std;

class Node{
    
public:
    int first, second;
    Node(int first, int second){
        this->first = first;
        this->second = second;
    }
    
};

class Compare{
public:
    bool operator() (Node a, Node b){
        return a.second > b.second;
    }
};

// first = end node
// second = cost
vector<Node> edge[200001];
int dist[200001];
int v, w;
priority_queue<Node, vector<Node>, Compare> bfs_q;

void dij(int node){
    vector<Node> &cur = edge[node];

    int cost;
    for(int i = 0; i < cur.size(); i++){
        cost = dist[node] + cur[i].second;
        if(cost < dist[cur[i].first]){
            dist[cur[i].first] = cost;
            bfs_q.push({cur[i].first, cost});
        } 
    }
}

void bfs(int node){

    bfs_q.push({node, 0});
    dist[node] = 0;
    while(!bfs_q.empty()){
        int temp = bfs_q.top().first;
        //cout << bfs_q.top().first << " " << bfs_q.top().second << endl;
        bfs_q.pop();
        dij(temp);
    }
}




void solve(){
    cin >> v >> w;
    int start, buff_s, buff_e, buff_w;
    cin >> start;

    for(int i = 0; i < w; i++){
        cin >> buff_s >> buff_e >> buff_w;
        edge[buff_s].push_back(Node(buff_e, buff_w));
    }
    //memset(visited, false, v+1);
    fill(dist, dist+v+1, INT_MAX);

    bfs(start);

    for(int i = 1; i <= v; i++){
        if(dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.precision(10);
    solve();

    return 0;
}
