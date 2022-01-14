#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> u;
priority_queue<long long> d;
priority_queue<long long> sd;
priority_queue<long long> su;

void cleanse(){
    while(su.size() && d.top() == su.top()){
        su.pop();
        d.pop();
    }
    while(sd.size() && u.top() == sd.top()){
        u.pop();
        sd.pop();
    }

}

void initialize() {
    u = priority_queue<long long>();
    su = priority_queue<long long>();
    d = priority_queue<long long>();
    sd = priority_queue<long long>();
}
void solve(){
    
    long long N, M;
    
    cin >> N;
    long long buff, cnt;
    char tp;
    for(int i = 0; i < N; i++){
        cin >> M;
        cnt = 0;
        initialize();
        for(int j = 0; j < M; j++){
            cin >> tp >> buff;
            if(tp == 'I'){
                u.push(buff);
                d.push(-buff);
                cnt++;
            }
            else if(cnt > 0){
                cnt--;
                if(buff < 0){
                    sd.push(-d.top());
                    d.pop();
                }
                else{
                    su.push(-u.top());
                    u.pop();
                }
                if(!cnt){
                    initialize();
                }
                cleanse();
            }
        }
        if(cnt) cout << u.top() << ' ' << -d.top() << '\n';
        else cout << "EMPTY" << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}