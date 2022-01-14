#include <bits/stdc++.h>

using namespace std;

vector<int> x, y;

void solve(){

    int buff, t, n, ans=0;

    cin >> buff; 
    x.push_back(buff);
    x.push_back(0);
    cin >> buff;
    y.push_back(buff);
    y.push_back(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t >> buff;
        if(t) x.push_back(buff);
        else y.push_back(buff);
    }

    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    //cout << y[0];


    for(int i = 0; i < x.size()-1; i++){
        for(int j = 0; j < y.size()-1; j++){
            if(ans < (x[i+1]-x[i])*(y[j+1]-y[j])){
                //cout << "x1 = " << x[i] << " x2 = " << x[i+1] << endl;
                ans = (x[i+1]-x[i])*(y[j+1]-y[j]);
            }
        }
    }

    cout << ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}