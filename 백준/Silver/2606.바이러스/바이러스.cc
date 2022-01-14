#include <bits/stdc++.h>
using namespace std;

bool vs[101];
vector<int> E[101];
int ans;

void dfs(int num){

    if(vs[num]) return;
    // cout << "checking " << num << endl;
    vs[num] = 1;
    ans++;
    vector<int>& node = E[num];
    for(int i = 0; i < node.size(); i++){
        dfs(node[i]);
    }
}

void solve(){

    int N, a, b, c;

    cin >> N >> c;

    for(int i = 0; i < c; i++){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    dfs(1);

    cout << ans-1;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
