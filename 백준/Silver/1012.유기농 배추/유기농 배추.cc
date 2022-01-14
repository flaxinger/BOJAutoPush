#include <bits/stdc++.h>
#define MAX 50

using namespace std;

int arr[MAX][MAX];
int row, col, n, cnt;

void check(int x, int y){
    
    arr[x][y] = 0;
    if(x > 0 && arr[x-1][y]) check(x-1, y);
    if(x < row-1 && arr[x+1][y]) check(x+1, y);
    if(y > 0 && arr[x][y-1]) check(x,y-1);
    if(y < col-1 && arr[x][y+1]) check(x, y+1);
}
    

void solve(){
    
    cin >> row >> col >> n;
    cnt = 0;
    int r, c;
    for(int i = 0; i < n; i++){
        cin >> r >> c;
        arr[r][c] = 1;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j]==1){
                check(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout << "got here\n";
    int c;
    cin >> c;
    while(c>0){
        solve();
        c--;
    }
    return 0;
}

