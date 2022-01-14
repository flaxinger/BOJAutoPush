#include <bits/stdc++.h>

using namespace std;

class Node{

public:
    int dir, cost;
    Node(int dir, int cost){
        this->dir = dir;
        this->cost = cost;
    }
};
class Compare{

public:
    bool operator() (Node a, Node b){
        return a.cost > b.cost;
    }

};

int E, V, starting, target, stp;
vector<Node> routes[1001];
priority_queue<Node, vector<Node>, Compare> pq;
int dp[1001];

void dij(int node){
    
    if(node == target){
        stp = true;
        cout << dp[node];
        return;
    }
    vector<Node> &cur = routes[node];
    
    int temp;
    for(int i = 0; i < cur.size(); i++){
        temp = dp[node] + cur[i].cost;
        if(temp < dp[cur[i].dir]){

            dp[cur[i].dir] = temp;
            pq.push(Node(cur[i].dir, temp));
            // if(cur[i].dir == target){
            //     stp = true;
            //     cout << temp;  
            // } 
        }
    }
}

void func(int node){
    dp[node] = 0;
    pq.push(Node(node, 0));
    
    int temp;
    while(!pq.empty()){
        if(stp == true) return;
        temp=pq.top().dir;
        //cout << temp << " dist: " << dp[temp] << endl;
        pq.pop();
        dij(temp);
    }
}

void solve(){
    cin >> E >> V;
    int s, e, c;
    for(int i =0; i< V; i++){
        cin >> s >> e >> c;
        routes[s].push_back(Node(e, c));
    }
    
    fill(dp, dp+1+E, INT_MAX);
    cin >> starting >> target;
    
    func(starting);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}
