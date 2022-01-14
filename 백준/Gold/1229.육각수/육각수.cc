#include <bits/stdc++.h>

using namespace std;

long long arr[800];
int dp[1000001], limmit;
long long target;

void func(){
    arr[0] = 1;
    arr[1] = 6;

    int idx = 2;
    
    while(arr[idx-1] < 1000000){
        arr[idx] = arr[idx-1]+idx*6-(idx*2-1);
        //cout << "arr[" << idx << "] = " << arr[idx] << endl;
        idx++;
    }
}

void func2(int num, int cnt, int start){
    //cout << num << ' ' <<  cnt << ' ' << start << endl;
    int temp_diff;
    if(cnt == limmit || num == 0){
        return;
    }
    if(dp[num]!= 7){
        return;  
    } 
    for(int i = start; i >= 0; i--){
        if(arr[i] <= num){
            //cout << num << ' ' << arr[i] << endl;
            temp_diff = num - arr[i];
            if(temp_diff == 0) dp[temp_diff] = 0;
            else func2(temp_diff, cnt+1, i);   
            if(dp[temp_diff] + 1 < dp[num]) 
                dp[num] = dp[temp_diff] + 1;
        }
    }
    return;
} 

void solve(){
    cin >> target;
    limmit = 4;
    if(target < 146859) limmit = 4;
    if(target < 131) limmit = 5;
    if(target < 27) limmit = 6;
    func();
    fill(dp, dp+1000001, 7);
    dp[0] = 0;
    dp[1] = 1;
    func2(target, 0, 707);
    //cout << "this is arr[707] = " << arr[707] << endl;
    //for(int i = 0; i < 20; i++) cout << "arr[" << i << "] = " << arr[i] << '\n';
    cout << dp[target];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    //printf("%d", 'z');
    return 0;
}



