#include <bits/stdc++.h>
using namespace std;

void solve(){

    int N, r, c, ans, s, a, b;

    cin >> N >> r >> c;

    N = pow(2, N);
    s = N*N;

    ans = 0;
    N /= 2;
    while(N > 0){
        s /= 4;
        // cout << N << endl;
        a = r/N * s * 2;
        b = c/N * s;
        ans += a + b;
        //cout << a << " + " << b << " = " << ans << endl;
        r -= (r/N * N);
        c -= (c/N * N);
        //cout << "\tremainder r = " << r << " c = " << c << endl;
        N /= 2;
    }
    // cout << "final ans ";
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
