#include <bits/stdc++.h>
using namespace std;
int N;

priority_queue<int> pq;

void solve(){
    
    cin >> N;
    int buff;
    while(N--){
        cin >> buff;
        if(!buff){
            if(pq.size()){
                cout << -pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
        else pq.push(-buff);
    }        
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}