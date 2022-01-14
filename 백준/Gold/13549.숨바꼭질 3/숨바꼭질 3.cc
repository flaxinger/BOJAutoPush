#include <bits/stdc++.h>
using namespace std;
int N, M;

queue<pair<int, int>> q;
int vs[100001];
void solve(){
    
    cin >> N >> M;

    q.push({N, 0});
    int num2, num, cnt;
    while(q.front().first != M){
        num2 = num = q.front().first;
        cnt = q.front().second +1;
        
        while(num2*2 <= 100000 && !vs[num2*2]){
            q.push({num2*2, cnt-1});
            vs[num2*2] = 1;
            num2*=2;
        }
        if(num-1 >= 0 && !vs[num-1]){
            q.push({num-1, cnt});
            vs[num-1] = 1;
        }
        if(num+1 <= 100000 && !vs[num+1]){
            q.push({num+1, cnt});
            vs[num+1] = 1;
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