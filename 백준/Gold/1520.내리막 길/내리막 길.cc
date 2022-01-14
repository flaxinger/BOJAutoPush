#include <bits/stdc++.h>
using namespace std;

int a[501][501];
long long dp[501][501];
int total, r, c;

long long search(int x, int y){

    int &pos = a[x][y];
    long long &sum = dp[x][y];
    
    if(x == r && y == c) return 1;
    if(sum != -1) return sum;
    
    //vs[x][y] = true;
    sum = 0;
    
    if(x > 0){
        if(pos > a[x-1][y]){
            sum += search(x-1,y);
        }            
    }
    if(y > 0){
        if(pos > a[x][y-1]){
            sum += search(x,y-1);          
        }
    }
    if(x < r){
        if(pos > a[x+1][y]){
            sum +=search(x+1,y);          
        }
    }
    if(y < c){
        if(pos > a[x][y+1]){
            sum +=search(x,y+1);          
        }
    }    
    return sum;
}



void solve(){

    cin >> r >> c;

    //memset(vs, false, sizeof(vs));
    fill(&dp[0][0], &dp[0][0]+251001, -1);
    for(int i= 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    r--;
    c--;
    cout << search(0,0) << endl;
    // cout << dp[499][499] << endl;
    // for(int i= 0; i < r+1; i++){
    //     for(int j = 0; j < c+1; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }
    //cout << dp[500][500];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

