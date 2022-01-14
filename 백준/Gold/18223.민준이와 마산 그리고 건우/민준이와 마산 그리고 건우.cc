#include <bits/stdc++.h>

using namespace std;

int V, E, P;

priority_queue<pair<pair<long long, int>, bool>> pq;
vector<pair<int, long long>> nodes[5001];
int dist[5001];

void solve(){

    cin >> V >> E >> P;

    int a, b, c;
    fill(dist, dist+5001, INT_MAX);
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        nodes[a].push_back({b, c});
        nodes[b].push_back({a, c});
    }

    pq.push({{0, 1}, 0});

    int at, found, nat, pr= true;
    long long ncost, cost, limmit = 200000000000;
    while(!pq.empty()){
        cost = -pq.top().first.first;
        at = pq.top().first.second;
        found = pq.top().second;

        pq.pop();
        
        if(dist[at] < cost) continue;
        if(cost > limmit) break;
        if(at == P) found = 1;
        
        //cout << "V[" << at << "] = {" << cost << ',' << found << '}' << endl;        
        if(at == V){
            if(found) pr = false;
            limmit = cost;
        }
        

        for(int i = 0; i < nodes[at].size(); i++){
            nat = nodes[at][i].first;
            ncost = nodes[at][i].second;
            if(cost + ncost <= dist[nat]){
                dist[nat] = cost + ncost;
                pq.push({{-(cost + ncost), nat}, found});
            }
        }

    }
    if(pr) cout << "GOOD BYE";
    else cout << "SAVE HIM";
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}