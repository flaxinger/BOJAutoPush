#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a, b;
    cin >> a >> b;

    if(a > b) cout << '>';
    else if(a < b) cout << '<';
    else cout << "==";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
