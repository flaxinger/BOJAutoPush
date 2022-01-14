#include <bits/stdc++.h>

using namespace std;

int arr[100001];
long long n, k, pwr, rem, cnt, n_t;
string n_b;
void solve(){
    cin >> n_b >> k;

    pwr = pow(10, n_b.length());
    n_t = n = stoi(n_b);

    while(1){
        cnt++;
        rem = n_t%k;
        if(rem==0){
            cout << cnt;
            return;
        }
        if(arr[rem]){
            cout << -1;
            return;
        }
        arr[rem]=1;
        n_t = n+rem*pwr;
    }

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    solve();
    return 0;
}