#include <bits/stdc++.h>
using namespace std;

int N;
int arr[10001];
int cnt[10001];

void solve(){

    cin >> N;
    int idx=0;
    for(int i = 0; i < N; i++){
        cin >> arr[idx];
        if(cnt[arr[idx]] > 0){
            cnt[arr[idx]]++;
        }
        else{
            cnt[arr[idx]]++;
            idx++;
        }
    }
    sort(arr, arr+idx);
    for(int i = 0; i < idx; i++){
        if(arr[i] != 0){
            while(cnt[arr[i]]--){
                cout << arr[i] << '\n';
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
