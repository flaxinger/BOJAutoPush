#include <bits/stdc++.h>
using namespace std;

int v[20];
int c, target;
int result = 0;


void find(int idx, int sum){

    if(idx>=c) return;

    sum+=v[idx];
    if(sum==target) result++;

    find(idx+1, sum);
    find(idx+1, sum-=v[idx]);
}


void solve(){
    int buff;

    cin >> c >> target;

    for(int i = 0; i < c; i++){
        cin >> v[i];
    }

    find(0, 0);

    cout << result;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}