#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int N, cnt, ans;
    string buff;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin>>buff;
        ans = 0;
        cnt = 0;
        for(int j = 0; j < buff.length(); j++){
            if(buff[j] == 'O'){
                if(cnt == 0) cnt =1;
                else cnt++;
                ans+=cnt;
            }
            else cnt = 0;
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
