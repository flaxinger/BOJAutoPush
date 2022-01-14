#include <bits/stdc++.h>
using namespace std;
int N, M;

queue<pair<int, int>> q;
int vs[100001];
void solve(){
    
    cin >> N >> M;

    q.push({N, 0});
    int num, cnt;
    while(q.front().first != M){
        num = q.front().first;
        cnt = q.front().second +1;
        
        if(num-1 >= 0 && !vs[num-1]){
            q.push({num-1, cnt});
            vs[num-1] = 1;
        }
        if(num+1 <= 100000 && !vs[num+1]){
            q.push({num+1, cnt});
            vs[num+1] = 1;
        }
        if(num*2 <= 100000 && !vs[num*2]){
            q.push({num*2, cnt});
            vs[num*2] = 1;
        }
        q.pop();
    }
    cout << q.front().second;
        
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}