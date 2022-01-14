//https://velog.io/@flaxinger/%EB%B0%B1%EC%88%9C%EC%BD%94-1325
#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int dp[10001];
int vs[10001];
int start, cycle, icycle;
vector<int> cv;

int dfs(int idx){   
    int sum = 1;
    vs[idx] = 1;
    for(int i = 0; i < v[idx].size(); i++){
        int next = v[idx][i];
        if(start == next && vs[next] == 1){
            icycle = 1;
            cycle = 1;
        }   
        if(!vs[next]){
            icycle = 0;
            sum += dfs(next);
            if(icycle){
                cv.push_back(next);
            }
        } 
    }
    return sum;
}

void solve(){
    int max=0, c, n, o, t; 
    vector<int> ans;
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        cin >> o >> t;
        v[t].push_back(o);
    } 
    for(int i = 1; i <= c; i++){
        if(dp[i]==0){
            cycle = 0;
            start = i;
            int temp = dfs(i);
            fill(vs,vs+c+1,0);
            if(cycle){
                for(int i = 0; i < cv.size(); i++){
                    dp[cv[i]] = temp;
                }
                cv.clear();
            }
            if(temp == max){
                ans.push_back(i);
            }
            if(temp > max){
                max = temp;
                ans.clear();
                ans.push_back(i);
            }
        }
        else if(dp[i] == max){
            ans.push_back(i);
        }
    }  
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}