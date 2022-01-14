#include <bits/stdc++.h>
using namespace std;
 
queue<int> q;
bool dp[10001];
int route[10001];
char op[10001];
int D(int n){
    return (n*2)%10000;
}
 
int S(int n){
    if(n > 0){
        return n-1;    
    }
    else{
        return 9999;
    }
}
 
int L(int n){
 
    string s = to_string(n);
    while(s.length() < 4) s= '0'+s;
    char t = s[0];
    for(int i = 0; i < 3; i++){
        s[i]=s[i+1];
    }
    s[3] = t;
    return stoi(s);
}
 
int R(int n){
 
    string s = to_string(n);
    while(s.length() < 4) s= '0'+s;
    char t = s[3];
    for(int i = 3; i > 0; i--){
        s[i] = s[i-1];
    }
    s[0] = t;
    return stoi(s);
}
 
void solve(){
 
    int N, a, b;
    cin >> N;
 
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        q = queue<int>();
        memset(dp, 0, sizeof(dp));
        q.push(a);
        dp[a] = 1;
        route[a] = 10000;
        int f, dd, ss, ll, rr;
        string s;
        while(q.front() != b){
            f = q.front();
            q.pop();

            dd = D(f); ss = S(f); ll = L(f); rr = R(f);

            if(!dp[dd]){
                q.push(dd);
                dp[dd]=1;
                route[dd]=f;
                op[dd]='D';
            }
            if(!dp[ss]){
                q.push(ss);
                dp[ss] = 1;
                route[ss]=f;
                op[ss]='S';
            }
            if(!dp[ll]){
                q.push(ll);
                dp[ll] = 1;
                route[ll]=f;
                op[ll]='L';
            }
            if(!dp[rr]){
                q.push(rr);
                dp[rr] = 1;
                route[rr]=f;
                op[rr]='R';
            }     
        }
        s="";
        f = q.front();
        while(route[f]!=10000){
            s = op[f] + s;
            f = route[f];
        }
        cout << s << '\n';
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    //cout << L(123) << ' ' << R(123) << ' ' << S(0) << ' ' << D(0) << ' ' << D(1111);
    return 0;
}