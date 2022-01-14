#include <bits/stdc++.h>
using namespace std;

main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    priority_queue<int> q;
    int N, buff;
    
    cin >> N;
    for(int i =0; i < N; i++){
        cin >> buff;
        if(!buff){
            if(q.size()){
                cout << q.top() << '\n';
                q.pop();
            }
            else cout << 0 << '\n';
        }
        else q.push(buff);
    }
}