#include <bits/stdc++.h>
using namespace std;

int arr[10];

void solve(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) cin >> arr[i];
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(arr[j]==0){
                printf("%d ", j+1);
                for(int k = j; k >= 0; k--){
                    arr[k]--;
                }
                break;
            }
        }
    }    
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    solve();
    return 0;
}