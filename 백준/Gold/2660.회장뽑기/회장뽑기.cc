#include <bits/stdc++.h>

using namespace std;

vector<int> E[51];
bool vs[51];
vector<int> ans[51];
int N, MD;

queue<pair<int, int>> q;

void bfs_(int n, int dp){

    //cout << "node " << n << " dp is " << dp << endl;
    if(dp > MD) MD = dp;
    vector<int> a = E[n];
    for(int i = 0; i < a.size(); i++){
        if(!vs[a[i]]){
            q.push({a[i], dp+1});
            vs[a[i]] = 1;
        }
    }
}


void bfs(int n){

    q.push({n, 0});
    vs[n] = 1;
    while(!q.empty()){
        bfs_(q.front().first, q.front().second);
        q.pop();
    }
}

void solve(){

    cin >> N;

    int one, two;
    cin >> one >> two;

    while(one != -1){
        E[one].push_back(two);
        E[two].push_back(one);
        cin >> one >> two;
    }

    for(int i = 1; i <= N; i++){
        memset(vs, 0, sizeof(vs));
        MD = 0;
        bfs(i);
        //cout << i << ": MD is " << MD << endl;
        ans[MD]. push_back(i);
    }
    
    for(int i = 1; i <= N; i++){
        //cout << "got here" << endl;
        if(ans[i].size() > 0){
            cout << i << " " << ans[i].size() << endl;
            sort(ans[i].begin(), ans[i].end(), less<int>());
            for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            break;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();

    return 0;
}

