#include <bits/stdc++.h>

using namespace std;

int board[101][101], dist[101][101], N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

priority_queue<pair<int, pair<int, int>>> pq;

void solve(){

    cin >> N >> M;

    string buff;
    for(int j = 1; j <= M; j++){
        cin >> buff;
        for(int i = 1; i <= N; i++){
            board[i][j] = buff[i-1]-48;
        }

    }

    memset(dist, 999999, sizeof(dist));

    pq.push({0, {1, 1}});

    int x, y, c, nx, ny;
    while(!pq.empty()){
        c = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;

        //cout << "[" << x << ',' << y << "] = " << c << '\n';

        pq.pop();

        if(dist[x][y] < c) continue;
        if(x == N && y == M){
            cout << c;
            break;
        }

        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx <= N && nx > 0 && ny <= M && ny > 0){
                if(board[nx][ny] && c+1 < dist[nx][ny]){
                    pq.push({-(c+1), {nx, ny}});
                    dist[nx][ny] = c+1;
                }
                else if(!board[nx][ny] && c < dist[nx][ny]){
                    pq.push({-c, {nx, ny}});
                    dist[nx][ny] = c;
                }
            }
        }  
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}
