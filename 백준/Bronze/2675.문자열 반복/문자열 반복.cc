#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    string a, ans;
    int N, R;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> R;
        cin >> a;
        ans = "";
        for(int j =0; j < a.length(); j++){
            for(int k = 0; k < R; k++) ans+=a[j];
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
