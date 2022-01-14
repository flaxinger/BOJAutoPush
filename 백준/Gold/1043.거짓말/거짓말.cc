#include <bits/stdc++.h>

using namespace std;

int N, M;
int people[51];
vector<int> conn[51];
bool vs[51];

void dfs(int node){
    
    vs[node] = 1;
    
    //cout << "size of " << node << " is " << conn[node].size() << endl;
    for(int i = 0; i < conn[node].size(); i++){
        if(!vs[conn[node][i]]) dfs(conn[node][i]);
    }
}


void solve(){
    
    int knows[51], buff[51];
    
    cin >> N >> M;
    
    int nn, n, result = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> knows[i];
    }
    vector<vector<int>> party;
    vector<int> tmp;
    for(int i = 0; i < M; i++){
        party.push_back(tmp);
        cin >> nn;
        for(int j = 0; j < nn; j++) cin >> buff[j];
        for(int j = 0; j < nn; j++){
            party[i].push_back(buff[j]);
            for(int k = j+1; k < nn; k ++){
                //cout << "Sould be pushing conn "  <<  j << " and " << k << endl;
                if(find(conn[buff[k]].begin(), conn[buff[k]].end(), buff[j]) == conn[buff[k]].end()) conn[buff[k]].push_back(buff[j]);
                if(find(conn[buff[j]].begin(), conn[buff[j]].end(), buff[k]) == conn[buff[j]].end()) conn[buff[j]].push_back(buff[k]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        dfs(knows[i]);
    }
    
    bool a;
    //for(int i = 1; i <= N; i++) cout << vs[i] << ' ';
    for(int i = 0; i < M; i++){
        a = true;
        for(int j = 0; j < party[i].size(); j++){
            if(vs[party[i][j]]) a= false;
        }
        if(a) result++;
    }

    cout << result;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}
