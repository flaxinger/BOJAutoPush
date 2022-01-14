#include <bits/stdc++.h>
using namespace std;

int arr[1001][3];
int dp[1001][3];
int n;


void find(int idx, int ban){

    if(idx >= n) return;

    if(dp[idx][ban] != INT_MAX) return;

    int current = 0;
    for(int i = 0; i < 3; i++){
        if(i == ban) continue;
        else{
            find(idx+1, i);
            current = arr[idx][ban] + dp[idx+1][i];
            if(current < dp[idx][ban]) dp[idx][ban] = current;
        }
    }
}

void solve(){
    cin >> n;
    
    fill(&dp[0][0], &dp[0][0]+n*3, INT_MAX);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }

    for(int i = 0; i < 3; i++) find(0, i);
    cout << min(dp[0][0], min(dp[0][1], dp[0][2]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

