#include <bits/stdc++.h>

using namespace std;

int dp[100];
int n, best;
vector<pair<int, int>> paper;


int func(int idx){
    //cout << "\t\tin loop with idx " << idx << endl;
    if(dp[idx]) return dp[idx];
    
    dp[idx] = 1;
    for(int i = 0; i < n; i++){
        if(paper[idx].first >= paper[i].first && paper[idx].second >= paper[i].second && idx!=i){
            if(dp[idx] < 1 + func(i)){
                //cout << "\tsaved " << i << endl;
                dp[idx] = dp[i]+1;  
            }
            //cout << "\t\t" << i << " is " << dp[i] << endl;
        }
    }
    if(dp[idx] > best) best = dp[idx];
    return dp[idx];

}
void solve(){
    cin >> n;
    int buff1, buff2;
    for(int i = 0; i < n; i++){
        cin >> buff1 >> buff2;
        if(buff1 > buff2) paper.push_back({buff1, buff2});
        else paper.push_back({buff2, buff1});
        //cout << paper[i].first << ' ' << paper[i].second << endl;
    }

    //cout << func(4) << endl;
    for(int i = 0; i < n; i++){
        //cout << "in " << i << endl;
        //cout << paper[i].first << ' ' << paper[i].second << endl;
        func(i);
    }

    cout << best;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}