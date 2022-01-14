#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<char> v;
vector<string> ans;
vector<int> vs;
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

void func(string a, int idx){
    
    //cout << a << endl;
    int cnt = 0;
    if(idx == n){
        for(int i = 0; i < n; i++){
            if(find(a.begin(), a.end(), vowels[i]) != a.end()) cnt++;
        }
        // for(int i = 0; i < n-1; i++){
        //     if(a[i] > a[i+1]) return;
        // }
        if(cnt < n-1 && cnt > 0) ans.push_back(a);
        return;
    }
    
    for(int i = 0; i < m; i++){
        if(vs[i]==0 && (idx == 0 || v[i] > a[idx-1])){
            a[idx]=v[i];
            vs[i] = 1;
            func(a, idx+1);    
            vs[i] = 0;
        }
    }
}

void solve(){
    cin >> n >> m;
    char buff;
    for(int i = 0; i < m; i++){
        cin >> buff;
        v.push_back(buff);
        vs.push_back(0);
    }
    string a;
    for(int i = 0; i < n; i++){
        a+='0';
    }
    func(a, 0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
