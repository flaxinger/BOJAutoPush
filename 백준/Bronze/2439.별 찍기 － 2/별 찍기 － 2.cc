#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a;
    cin >> a;

    for(int i = a; i >0; i--){
        for(int j = 1; j < i; j++) cout << ' ';
        for(int j = i; j <= a; j++) cout << '*';
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
