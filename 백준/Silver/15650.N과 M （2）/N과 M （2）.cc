#include <bits/stdc++.h>
using namespace std;
int N, M;

queue<pair<int, int>> q;
int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
void solve(){
    
    cin >> N >> M;
    int cnt =0;
    // cout << (1<<N);
    vector<vector<int>> a;
    vector<int> b;
    for(int i =0; i < 1<<N; i++){
        cnt = 0;

        for(int j = 0; j < N; j++){
            if(i & 1<<j) cnt++;
        }
        if(cnt == M){
            for(int j = 0; j < N; j++){
                if(i & 1<<j) b.push_back(arr[j]);
            }   
            a.push_back(b);
            b.clear();
        }
    }
    sort(a.begin(), a.end(),
        [](const auto& ai, const auto& bi){
            for(int i = 0; i < ai.size(); i++){
                if(ai[i]!=bi[i]) return ai[i] < bi[i];
            }
            return true;
        });

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
        
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}