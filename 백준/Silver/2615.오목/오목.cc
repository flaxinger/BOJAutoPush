#include <bits/stdc++.h>

using namespace std;

int board[19][19];
int dx[8] = {-1, -1, 0, 1, 1};
int dy[8] = {0, -1, -1, -1, 0};
int ans, ax, ay;

void func(int x, int y, int val, int cnt, int dir){

    int nx, ny, ox, oy;

    if(!val && board[x][y]&&ans==0) val = board[x][y]; 
    if(val == 0) return;

    //cout << "[" << x << "][" << y << "] -- val = " << val << ", cnt = " << cnt << ", dir = " << dir << endl;
    if(dir !=-1){
        nx = x+dx[dir];
        ny = y+dy[dir];

        if(cnt == 4){
            if(ny >= 0 && nx >=0 && ny < 19 && nx < 19){
                if(board[nx][ny]!=val){
                    ax = x;
                    ay = y;
                    ans = val;
                    return;
                }
            }
            else{
                ax = x;
                ay = y;
                ans = val;
                return;
            }
        }
        else{
            if(ny >= 0 && nx >=0 && ny < 19 && nx < 19){
                if(board[nx][ny] == val)
                    func(nx, ny, val, cnt+1, dir);
            }
        }
    }
    else{
        for(int i = 0; i < 8; i++){
            nx = x+dx[i];
            ny = y+dy[i];
            ox = x-dx[i];
            oy = y-dy[i];
            if(ny >= 0 && nx >=0 && ny < 19 && nx < 19){
                //cout << "\t [" << nx << "][" << ny << "]= " << board[nx][ny] << " vs [" << ox << "][" << oy << "]=" << board[ox][oy] << endl;
                if(oy >= 0 && ox >=0 && oy < 19 && ox < 19){
                    if(board[nx][ny] == val && board[ox][oy] != val) 
                        func(nx, ny, val, cnt+1, i);
                }
                else if(board[nx][ny] == val) func(nx, ny, val, cnt+1, i);
            }
        }
    }
}


void solve(){
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            cin >> board[i][j];

    //cout << "aaa" << endl;
    for(int i = 18; i >= 0; i--)
        for(int j = 18; j >= 0; j--)
            func(i, j, 0, 0, -1);

    if(ans){
        cout << ans << endl << ax+1 << ' '<< ay+1;
    }
    else cout << ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}