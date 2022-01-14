#include <bits/stdc++.h>
using namespace std;
string A, B;
int N, M;
short dp[1001][1001];

int func(int x, int y){

    if(x==N ||y == M) return 0;
    if(dp[x][y]> -1) return dp[x][y];
    dp[x][y] = 0;
    
    int i = 0, j= 0, k= 0;
    i = func(x+1, y+1);
    if(A[x]==B[y]) i++;
    j = func(x+1, y);
    k = func(x, y+1);

    return dp[x][y] = max(i, max(j, k));
}

void solve(){
    cin >> A >> B;
    N = A.length();
    M = B.length();
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}