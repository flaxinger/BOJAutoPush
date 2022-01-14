#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int a;
    cin >> a;

    if(a % 400 == 0) cout << 1;
    else if(a%4 == 0 && a%100!= 0) cout << 1;
    else cout << 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
