#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int a, b, ans;

    for(int i = 0; i < 8; i++){
        cin >> a;
        if(i == 1){
            if(b > a) ans = 2;
            else if(b < a) ans = 0;
        }
        else if(i > 1){
            if(ans == 0 && b > a) ans = 1;
            if(ans == 2 && b < a) ans = 1;
        }
        b = a;
    }

    if(ans == 0) cout << "ascending";
    else if(ans == 1) cout << "mixed";
    else cout << "descending";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
