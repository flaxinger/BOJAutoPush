#include <bits/stdc++.h>
using namespace std;
short N, board[20][20], cur_size=2, remain = 2, ans=0, lim;
bool vs[20][20];
priority_queue<short> food;
// int dx[4] = {-1, 0, 0, 1};
// int dy[4] = {0, -1, 1, 0};
short dx[4] = {-1, 0, 0, 1};
short dy[4] = {0, -1, 1, 0};

struct shark{
    short x, y, cnt;
};

struct Compare{
    bool operator() (shark a, shark b)
    {
        if(a.cnt!=b.cnt){
            if(a.cnt > b.cnt){
                return true;
            }else return false;
        }
        if(a.x!=b.x){
            if(a.x > b.x){
                return true;
            }else return false;
        }
        if(a.y > b.y){
            return true;
        }else return false;
    }
};

shark cur_pos;
queue<shark> q;
priority_queue<shark, vector<shark>, Compare> candidate;

void search(shark pos){

    if(pos.cnt > lim) return;
    short x = pos.x;
    short y = pos.y;
    short cnt = pos.cnt;
    vs[x][y] = 1;
    if(board[x][y] < cur_size && board[x][y] > 0){
        candidate.push(pos);
        lim = cnt;
    }
    short nx, ny;
    for(short i = 0; i < 4; i++){
        nx = dx[i]+x;
        ny = dy[i]+y;
        if(ny >= 0 && nx >= 0 && nx < N && ny < N && !vs[nx][ny] && board[nx][ny] <= cur_size){
            q.push({nx, ny, 1 + cnt});
        }
    }
}

void solve(){
    cin >> N;
    short buff;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                cur_pos = {i, j, 0};
                board[i][j] = 0;
            }
            else if(board[i][j] > 0) food.push(-board[i][j]);
        }
    }
    shark ss;
    while(food.size() && -food.top() < cur_size){
        food.pop();
        q.push(cur_pos);
        lim = 1000000;
        while(q.size()){
            ss = q.front();
            q.pop();
            search(ss);
        }
        if(candidate.size()){
            cur_pos = candidate.top();
            board[cur_pos.x][cur_pos.y] = 0;
            if(remain > 1) remain--;
            else{
                cur_size++;
                remain = cur_size;
            }
            q = queue<shark>();
            candidate = priority_queue<shark, vector<shark>, Compare>();
            ans+=cur_pos.cnt;
            cur_pos.cnt = 0;
        }
        memset(vs, 0, sizeof(vs));
    }
    cout << ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}