#include <bits/stdc++.h>

using namespace std;

vector<int> arr[101];
int vs[101], ans[101], track[101], in_cycle[101];
int best = 0, dimen, start;

void dfs(int a, int depth){
    
    track[depth] = a;
    vs[a] =1;
    //cout << "\tvisited note " << a << "\tdepth " << depth << endl;
    vector<int> &aaa = arr[a];
    for(int i = 0; i< aaa.size(); i++){
            
        if(!vs[aaa[i]]) dfs(aaa[i], depth+1);
        if(aaa[i] == start){
            
            for(int j = 0; j < depth+1; j++){
                if(!in_cycle[track[j]]){
                    ans[best] = track[j];  
                    best++;
                } 
                in_cycle[track[j]] = 1;
            }
            //cout << "\t\tsaving " << best << endl;        
        }
    }
    vs[a] = 0;

}

void solve(){
    cin >> dimen;
    
    int buff;
    for(int i = 1; i <= dimen; i++){
        cin >> buff;
        arr[buff].push_back(i);
    }
    
    for(int i = 1; i<=dimen; i++){
        start = i;
        //cout << "going in dfs " << i << endl;
        dfs(i, 0);
    }
    
    cout << best << endl;
    sort(ans, ans+best, less<int>());
    for(int i = 0; i < best; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
