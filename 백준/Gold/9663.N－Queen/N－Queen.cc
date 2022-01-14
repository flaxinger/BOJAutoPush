#include <bits/stdc++.h>
using namespace std;
int NN, N, B[15], ans;
 
bool chk(int x, int y){
    int i = x;
    while(i--){
        if(abs(abs(B[i]) - abs(y)) == x - i || y == B[i]) return false;
    }
    return true;
}
 
void trav(int x){
 
    if(x == N){
        ans++;
        return;
    }
    // if(n==NN) return;
 
 
    for(int i =0; i < N; i++){
        if(chk(x, i)){
            B[x] = i;
            trav(x+1);
        }
    }

}
 
void solve(){
    cin >> N;
    NN = N*N;
    trav(0);
    cout << ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}