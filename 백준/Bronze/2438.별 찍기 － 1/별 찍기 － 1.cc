#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a;
    cin >> a;

    for(int i = 1; i <= a; i++){
        for(int j = 0; j < i; j++) cout << '*';
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
