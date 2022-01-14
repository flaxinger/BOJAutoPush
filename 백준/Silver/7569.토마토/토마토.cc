#include <bits/stdc++.h>
using namespace std;

int arr[100][100][100];
int X, Y, Z, ans, track;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

struct pos{
    int xpos, ypos, zpos, count;
};
deque<pos> q;

void func(int x, int y, int z, int cnt){

    if(cnt > ans) ans = cnt;
    //cout << track++ << ' ' << cnt << endl;
    int nx, ny, nz;
    pos p;
    arr[x][y][z] = 1;
    for(int i = 0; i < 6; i++){
        nx = x+dx[i];
        ny = y+dy[i];
        nz = z+dz[i];
        if(nx >= 0 && ny >= 0 && nz >=0 && nx < X && ny < Y && nz < Z){
            if(arr[nx][ny][nz]==0){
                p = {nx, ny, nz, cnt+1};
                q.push_back(p);
            }
        }
    }
    // for(int i = 0; i < Z; i++){  
    //     for(int j = 0; j < X; j++){
    //         for(int k = 0; k < Y; k++){
    //             cout<< arr[j][k][i] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void solve(){

    cin >> Y >> X >> Z;

    for(int i = 0; i < Z; i++)
        for(int j = 0; j < X; j++)
            for(int k = 0; k < Y; k++)
                cin >> arr[j][k][i];

    pos p;
    for(int i = 0; i < Z; i++){
        for(int j = 0; j < X; j++){
            for(int k = 0; k < Y; k++){
                if(arr[j][k][i]==1){
                    p = {j, k, i, 0};
                    q.push_back(p);
                    arr[j][k][i] = 0;
                }
            }
        }
    }
    if(q.empty()){
        cout << -1;
        return;
    }
    while(!q.empty()){
        if(arr[q.front().xpos][q.front().ypos][q.front().zpos] == 0) func(q.front().xpos, q.front().ypos, q.front().zpos, q.front().count);
        q.pop_front();
    }

    for(int i = 0; i < Z; i++){
        for(int j = 0; j < X; j++){
            for(int k = 0; k < Y; k++){
                if(arr[j][k][i] == 0){
                    cout << -1;
                    return;
                }
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
