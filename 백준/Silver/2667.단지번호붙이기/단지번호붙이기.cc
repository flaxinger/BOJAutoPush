#include <bits/stdc++.h>

using namespace std;

int plot[25][25];
vector<int> ans;
int dimen, current;

int xd[4] = {1, -1, 0, 0};
int yd[4] = {0, 0, 1, -1};

void mark(int x, int y){

    ans[current]++;
    plot[x][y]=0;
    for(int i = 0; i < 4; i++)
        if(x+xd[i] >= 0 && x+xd[i] < dimen && y+yd[i] >= 0 && y+yd[i] < dimen)
            if(plot[x+xd[i]][y+yd[i]])
                mark(x+xd[i], y+yd[i]);
    
}

void solve(){
    cin >> dimen;
    string a;
    for(int i = 0; i < dimen; i++){
        cin >> a;
        for(int j = 0; j < dimen; j++){
            plot[i][j] = a[j]-'0';
        }
    }
    
    for(int i = 0; i < dimen; i++){
        for(int j = 0; j < dimen; j++){
            if(plot[i][j]){
                ans.push_back(0);
                mark(i,j);
                current++;
            }
        }
    }
    
    sort(ans.begin(), ans.end(), less<int>());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}