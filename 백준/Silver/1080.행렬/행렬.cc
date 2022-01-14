#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<string> comp;


void d(int r, int c){
    for(int i = r; i < r+3; i++){
        for(int j = c; j < c+3; j++){
            v[i][j] = (v[i][j]=='0') ? '1' : '0';
        }
    }
}

int solve(){
    
    int r, c, buff;
    int count = 0;
    
    cin >> r >> c;
    
    
    
    for(int i = 0; i < r; i++){
        string temp;
        cin >> temp;
        comp.push_back(temp);
    }
    
    for(int i = 0; i < r; i++){
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    if(r < 3 || c < 3){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(v[i][j]!=comp[i][j]){
                    return -1;
                } 
            }
        }
        return 0;
    } 
    
    //cout << endl;
    //for(int k = 0; k < r; k++) cout << v[k] << endl;
    
    for(int i = 0; i < r-2; i++){
        for(int j = 0; j < c-2; j++){
            if(v[i][j]!=comp[i][j]){
                //cout << "\nChanging\n";
                d(i, j);  
                count++;
                //for(int k = 0; k < r; k++) cout << v[k] << endl;
            } 
        }
    }
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(v[i][j]!=comp[i][j]){
                return -1;
            } 
        }
    }
    return count;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << solve();
}

