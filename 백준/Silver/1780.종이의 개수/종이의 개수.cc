#include <bits/stdc++.h>
#define MAX 2187

using namespace std;

int arr[MAX][MAX];
//int done[MAX][MAX];
int n, sz, n_s, z_s, o_s;

int check(int startx, int starty){
    int temp = arr[startx][starty];
    int _temp = temp;
    for(int i = startx; i < startx+sz; i++){
        for(int j = starty; j < starty+sz; j++){ 
            if(arr[i][j] != temp){
                temp = 2;
                break;
            }
            
        }
        if(temp!=_temp) break;
    }
    
    if(temp!=2){
        for(int i = startx; i < startx+sz; i++)
            for(int j = starty; j < starty+sz; j++)
                arr[i][j] = 2;

    }
    return temp;
}
    

void solve(){
    
    cin >> n;
    sz = n;
    int result;
    o_s = 0;
    n_s = 0;
    z_s = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    while(sz > 0){
        
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";
        //cout << "sum is " << sum << " target is " << target << " sz is " << sz << " ad is " << ad << "\n";

        for(int i = 0; i < n; i+=sz){
            //cout << "i is "<< i << "\n";
            for(int j = 0; j < n; j+=sz){
                if(arr[i][j]!=2){
                    result = check(i,j);                    
                    if(result == -1){
                        n_s++;  
                    }
                    else if(result == 0){
                        z_s++;
                    }
                    else if(result == 1){
                        o_s++;
                    }
                }
            }
        }
        sz = sz/3;
    }
    cout << n_s << '\n' << z_s << '\n' << o_s << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << "got here\n";
    solve();
    return 0;
}

