#include <bits/stdc++.h>
using namespace std;

// [i][0] -> 최근 스텝은 무조건 점프인 최대값
// [i][1] -> 점프 상관 없는 최대값
long long dp[300][2];
long long arr[300];

void solve(){

    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    dp[0][0] = arr[0];
    dp[0][1] = arr[0]; 
    dp[1][1] = arr[0]+arr[1];
    dp[1][0] = arr[1];

    for(int i = 2; i < N; i++){
        dp[i][0] = dp[i-2][1] + arr[i];
        dp[i][1] = max(dp[i][0], dp[i-1][0]+arr[i]);
    }
    cout << dp[N-1][1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
