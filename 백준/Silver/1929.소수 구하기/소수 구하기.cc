#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int v[MAX];
int mn, mx;

void check(int a){
    for(int i = a + a; i <= mx; i+=a) v[i] = 1;
}

void solve(){
    cin >> mn >> mx;
    for(int i = 2; i * i <= mx; i++) if(!v[i]) check(i);
    if(mn < 2) mn = 2;
    for(int i = mn; i <= mx ; i++) if(!v[i]) cout << i << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

