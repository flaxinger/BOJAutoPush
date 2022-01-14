#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int buff, num = 1, arr[10]={0};
    for(int i = 0; i < 3; i++){
        cin >> buff;
        num *= buff;
    }
    string a = to_string(num);

    for(int i =0; i < a.length(); i++){
        arr[a[i]-'0']++;
    }
    for(int i= 0; i < 10; i++) cout << arr[i] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
