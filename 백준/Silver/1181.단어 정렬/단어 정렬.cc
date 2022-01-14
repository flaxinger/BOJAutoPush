#include <bits/stdc++.h>
using namespace std;

int N;
string arr[20000];

bool comp(string a, string b){

    if(a.length() == b.length()){
        for(int i = 0; i < a.length(); i++){
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
    }
    return a.length() < b.length();
}
void solve(){

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N, comp);

    for(int i = 0; i < N; i++){
        if(arr[i] != arr[i+1]) cout << arr[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
