#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,item[102][2],dp[102][100'003];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        cin >> item[i][0] >> item[i][1];
    }

    for(int i=1;i<=N;i++)
    {
        int weight = item[i][0], val=item[i][1];
        for(int j=0;j<=K;j++)
        {
            if(j<item[i][0]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+val);
        }
    }
    
    cout << dp[N][K];
}