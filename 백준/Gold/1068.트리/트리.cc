#include <bits/stdc++.h>

using namespace std;


int t[50];
int is_parent[50];
int n, leaf;

void rem(int a){
    is_parent[t[a]]--;
    if(is_parent[a]){
        for(int i = 0; i < n ; i++){
            if(t[i] == a){
                rem(i);
            }
        }
    }else leaf--;
}

void solve(){
    cin >> n;
    int rm = 0;
    for(int i =0; i < n; i++){
        cin >> t[i];
        if(t[i]!=-1){
            is_parent[t[i]]++;
        }
    }

    cin >> rm;

    for(int i =0; i < n; i++){
        if(!is_parent[i]){
            leaf++;
        }
    }
    // cout << leaf << endl;
    // for(int i = 0; i < n; i++) cout << t[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i++) cout << is_parent[i] << " ";
    // cout << endl;
    rem(rm);
    if(!is_parent[t[rm]]) leaf++;

    cout << leaf;
}






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}