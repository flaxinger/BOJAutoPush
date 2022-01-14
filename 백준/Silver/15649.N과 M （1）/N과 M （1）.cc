#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[9];
int used[9];

void func(int idx){
    
    if(idx==n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i<=m; i++){
        if(used[i]==0){
            arr[idx]=i;
            used[i] = 1;
            func(idx+1);
            used[i] = 0;
        }
    }
}

void solve(){
    cin >> m >> n;
    func(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}