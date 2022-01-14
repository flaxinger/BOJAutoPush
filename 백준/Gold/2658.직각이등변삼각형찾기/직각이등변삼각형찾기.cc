#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;
int chart[11][11];
int szx[11];
int szy[11];
int vs[11][11];
int xd[4] = {1, 1, 1, 0};
int yd[4] = {0, -1, 1, 1};
int xe[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int ye[8] = {1, -1, 0, 1, -1, 1, 0, -1};

void find(int x, int y){
    
    //cout << "currently at " << x << " " << y << endl;
    vs[x][y] = 1;
    szy[y]++;
    szx[x]++;
    for(int i = 0; i < 4; i++){
        if(x+xd[i] > 0 && x+xd[i] < 11 && y+yd[i] > 0 && y+yd[i] < 11){
            if(chart[x+xd[i]][y+yd[i]] && !vs[x+xd[i]][y+yd[i]])
                find(x+xd[i], y+yd[i]);
        }
    }

    int cnt = 0;
    for(int i = 0; i < 8; i++){
        if(x+xe[i] > 0 && x+xe[i] < 11 && y+ye[i] > 0 && y+ye[i] < 11)
            if(chart[x+xe[i]][y+ye[i]])
                cnt++;
    }
    if(cnt <= 3 && chart[x+xe[3]][y+ye[3]] + chart[x+xe[4]][y+ye[4]] + chart[x+xe[6]][y+ye[6]] + chart[x+xe[2]][x+ye[2]] < 3) ans.push_back({x,y});
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second) return true;
        return false;
    }
    return false;
}

void solve(){
    string a;
    
    for(int i = 1; i < 11; i++){
        cin >> a;
        for(int j = 1; j < 11; j++){
            chart[i][j] = a[j-1]-'0';
        }
    }
    // for(int i = 1; i < 11; i++){
    //     for(int j = 1; j < 11; j++)
    //         cout << chart[i][j];
    //     cout << endl;
    // }
    int aa = 0;
    for(int i = 0; i < 11; i ++){
        for(int j = 0; j < 11; j++){
            if(chart[i][j]){
                find(i, j);
                aa = 1;
                break;
            }
        }
        if(aa) break;
    }
    
    // tp == 1 is increasing/decreasing by one(right angle could be in the middle)
    // tp == 2 is increasing/decreasing by two().

    // for(int i = 1; i < 11; i++) cout << szy[i];
    // cout << endl;

    string type_is = "00000";
    string legit[5] = {"11000", "10000", "01000", "00010", "00100"};
    int idx;
    for(int i = 1; i < 11; i++){
        if(szy[i]){
            idx = i;
            while(szy[idx]+1 == szy[idx+1]){
                type_is[0] = '1';
                idx++;
            }
            while(szy[idx]-1 == szy[idx+1]){
                type_is[1] = '1';
                idx++;
            }
            while(szy[idx] + 2 == szy[idx+1]){
                type_is[2] = '1';
                idx++;            
            }
            while(szy[idx] - 2 == szy[idx+1]){
                type_is[3] = '1';
                idx++;
            }
            if(type_is == "01000") idx--;
            if(szy[idx+1] != 0) type_is[4] = '1';            
            break;
        }
    }

    if(type_is == "10000" || type_is == "01000"){
        for(int i = 1; i < 11; i++){
            if(szx[i]){
                idx = i;
                if(szx[idx]+1 == szx[idx+1]){
                    while(szx[idx]+1 == szx[idx+1]){
                        idx++;
                    }
                    if(szx[idx+1] != 0) type_is[4] = '1';
                }
                if(szx[idx]-1 == szx[idx+1]){
                    while(szx[idx]-1 == szx[idx+1]){
                        idx++;
                    }
                    if(szx[idx] != 0) type_is[4] = '1';
                }
                break;
            }
        }
    }
    if(type_is == "11000"){
        for(int i = 1; i < 11; i++){
            if(szx[i]){
                idx = i;
                if(szx[idx] -2 == szx[idx+1]){
                    while(szx[idx] - 2 == szx[idx+1]){
                        idx++;
                    }
                    if(szx[idx+1] != 0) type_is[4] = '1';
                }
                if(szx[idx] + 2 == szx[idx+1]){
                    while(szx[idx] + 2 == szx[idx+1]){
                        idx++;
                    }
                    if(szx[idx+1] != 0) type_is[4] = '1';
                }
                break;
            }
        }
    }

    if(type_is == "00100" || type_is == "00010"){
        for(int i = 1; i < 11; i++){
            if(szx[i]){
                idx = i;
                while(szx[idx] + 1 == szx[idx+1]){
                    idx++;
                }
                while(szx[idx] - 1 == szx[idx+1]){
                    idx++;
                }
                if(szx[idx] != 0) type_is[4] = '1';
                break;
            }
        }
    }
    
    //cout << type_is << endl;

    if(ans.size() == 4){

    }
    sort(ans.begin(), ans.end(), compare);

    if(find(legit, legit+5, type_is) != legit+5 && ans.size() == 3){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    else cout << 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();

    return 0;
}

