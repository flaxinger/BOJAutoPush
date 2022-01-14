#include <bits/stdc++.h>
using namespace std;
int N;
int ans, mark;
struct edge{
    int v;
    int cost;
};
vector<edge> V[100001];
short vs[100001];

pair<int, int> dfs(int vertex, int depth){

    vs[vertex]++;
    vector<edge> &cur = V[vertex];

    pair<int, int> result = {vertex, depth};
    pair<int, int> tmp= {0, 0};

    for(int i=0; i < cur.size(); i++){
        if(vs[cur[i].v]<mark){
            tmp = dfs(cur[i].v, depth+cur[i].cost);
            if(tmp.second > result.second){
                result = tmp;
            }
        }
    }
    return result;
}

void solve(){
    cin >> N;
    int buffv, ver;
    int buffe;
    
    for(int i = 1; i <= N; i++){
        cin >> ver;
        cin >> buffv;
        while(buffv>0){
            cin >> buffe;
            V[ver].push_back({buffv, buffe});
            cin >> buffv;
        }
    }

    for(int i =1; i <= N; i++){
        if(!vs[i]){
            mark = 1;
            pair<int, int> a = dfs(i,0);
            mark = 2;
            pair<int, int> b = dfs(a.first,0);
            int c = max(b.second, a.second);
            if(c > ans) ans =c;
        }
    }
    cout << ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}