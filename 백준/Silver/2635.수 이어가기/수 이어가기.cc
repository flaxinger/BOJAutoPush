#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans;
vector<int> temp;

void func(int in){
    temp.push_back(in);
    int idx = temp.size()-1;
    int nex = temp[idx-1] - temp[idx];
    if(nex >= 0) func(nex);
}
void solve(){
    cin >> n;

    for(int i = 0; i <= n; i++){
        temp.clear();
        temp.push_back(n);
        func(i);
        if(temp.size() > ans.size()){
            ans.clear();
            for(int i = 0; i < temp.size(); i++){
                ans.push_back(temp[i]);
            }
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}