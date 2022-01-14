#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a, ans =0;
    for(int i = 0; i < 5; i++){
        cin >> a;
        ans+=a*a;
    }
    cout << ans%10;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
