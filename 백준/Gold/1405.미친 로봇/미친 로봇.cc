#include <bits/stdc++.h>

using namespace std;

int n;
double prob[4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool board[29][29];
int x = 14, y = 14;
double result = 1;
int moves= 0;


void move(double p){

    if(board[x][y]){
        result -= p;
        return;
    }
    if(moves == n) return;
    moves++;
    
    board[x][y]=true;
    for(int i = 0; i < 2; i++){
        x+=dx[i];
        move(p*prob[i]);
        x-=dx[i];
    }
    for(int i = 2; i < 4; i++){
        y+=dy[i];
        move(p*prob[i]);
        y-=dy[i];

    }
    board[x][y]=false;
    moves--;
}


void solve(){
    cin >> n;
    for(int i = 0; i < 4; i++){
        cin >> prob[i];
        prob[i]/=100;
    }
    double start = 1;
    move(start);

    cout << fixed << result;
}






int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    solve();

    return 0;
}