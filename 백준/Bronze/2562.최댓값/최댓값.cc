#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int buff, ans=0, idx;

    for(int i =1; i <=9; i++){
        cin >> buff;
        if(buff > ans){
            ans = buff;
            idx = i;
        }
    }
    cout << ans << endl << idx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
