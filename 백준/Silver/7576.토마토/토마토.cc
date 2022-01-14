#include <bits/stdc++.h>
using namespace std;

int arr[1000][1000];
int X, Y, Z, ans, track;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
// int dz[6] = {0, 0, 0, 0, -1, 1};

struct pos{
    int xpos, ypos, count;
};
deque<pos> q;

void func(int x, int y, int cnt){

    if(cnt > ans) ans = cnt;
    //cout << track++ << ' ' << cnt << endl;
    int nx, ny;
    pos p;
    arr[x][y] = 1;

    for(int i = 0; i < 4; i++){
        nx = x+dx[i];
        ny = y+dy[i];
        // nz = z+dz[i];
        if(nx >= 0 && ny >= 0 && nx < X && ny < Y){
            if(arr[nx][ny]==0){
                p = {nx, ny, cnt+1};
                q.push_back(p);
            }
        }
    }
}

void solve(){

    cin >> Y >> X;

    for(int i = 0; i < X; i++)
        for(int j = 0; j < Y; j++)
            // for(int k = 0; k < Y; k++)
            cin >> arr[i][j];

    pos p;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            // for(int k = 0; k < Y; k++){
            if(arr[i][j]==1){
                p = {i, j, 0};
                q.push_back(p);
                arr[i][j] = 0;
            }
        }
    }
    if(q.empty()){
        cout << -1;
        return;
    }
    while(!q.empty()){
        if(arr[q.front().xpos][q.front().ypos]== 0) func(q.front().xpos, q.front().ypos, q.front().count);
        q.pop_front();
    }

    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            if(arr[i][j] == 0){
                cout << -1;
                return;
            }
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
