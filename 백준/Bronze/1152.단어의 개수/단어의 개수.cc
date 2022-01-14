#include <bits/stdc++.h>
using namespace std;

void solve(){

    string a;
    int ans = 0;
    getline(cin, a);
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ' ' && i == 0) ans--;
        if(a[i]==' '){
            ans++;
            if(i==a.length()-1) ans--;
        }
    }
    cout << ans+1;
    //cout << a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
