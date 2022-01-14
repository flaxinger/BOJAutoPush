#include <bits/stdc++.h>
using namespace std;


int dp[100000];
int v[400];

void solve(int target){

    int start, temp, stop, count;
    int i = 0;
    int best = 100000;


    while(i*i <= target) i++;
    i--;
    stop = i/5 *3;
    start = i;
    while(i > stop){
        count = 0;

        if(target/v[i] > 0){
            temp = target%v[i];
            if(dp[temp]==0) solve(temp);
            count = target/v[i] + dp[temp];      
            if(count < best) best = count;
        } 
        i--;
    }

    if(best==100000) dp[target] = 0;
    else dp[target] = best;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int target, i = 0;
    cin >> target;

    while(i*i <= target){
        v[i]=i*i;
        i++;
    }

    dp[1] = 1;

    solve(target);

    cout << dp[target];
}