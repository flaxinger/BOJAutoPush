#include <bits/stdc++.h>
using namespace std;

vector<int> d;
vector<int> b;
vector<vector<int>> m;


void dfs(int start){
    cout << start << ' ';
    d[start] = 0;

    for(int i = 0; i < m[start].size(); i++){
        int temp = m[start][i];
        if(d[temp]==-1) dfs(temp);
    }
}




void bfs(int start){
    
    queue<int> q;
    int cont, temp;
    q.push(start);

    b[start] = 0;
    while(!q.empty()){

        cont = q.size();
        while(cont>0){
            for(int i = 0; i < m[q.front()].size(); i++){
                temp = m[q.front()][i];
                if(b[temp]==-1){
                    q.push(temp);
                    b[temp] = 0;
                }

            }
            cout << q.front() << ' ';
            q.pop();
            cont--;
        }

    }

}

void solve(){

    int c, n, start;
    
    cin >> n >> c >> start;
    int buff1, buff2;
    
    for(int i = 0; i < n+1; i++){
        d.push_back(-1);
        b.push_back(-1);
    }

    for(int i = 0; i < n+1; i++){
        vector<int> temp;
        m.push_back(temp);
    }

    for(int i = 0; i < c; i++){
        cin >> buff1 >> buff2;
        m[buff1].push_back(buff2);
        m[buff2].push_back(buff1);
    }

    for(int i = 0; i < n+1; i++){
        sort(m[i].begin(), m[i].end());
    }


    dfs(start);
    cout << endl;
    bfs(start);
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}