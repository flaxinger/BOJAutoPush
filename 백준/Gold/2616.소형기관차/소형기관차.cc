#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[50000];

//value, idx 저장;
int dp[4][50000];

void solve(){
    cin >> N;
    for(int i = 0; i<N; i++) cin >> arr[i];
    for(int i = 1; i < N; i++) arr[i]+= arr[i-1];
    
    cin >> M;
    for(int i = 1; i < 4; i++){
        for(int j = i*M-1; j < N; j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-M] + arr[j] - arr[j-M]);
            //cout << dp[i][j-1] << ' ' << dp[i-1][j-M] + arr[j] - arr[j-M-1] << endl;
        }
    }

    cout << dp[3][N-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //test();
    solve();
    return 0;
}
