#include <bits/stdc++.h>
using namespace std;

short A[100][100], B[100][100], N, cur;
bool vs[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, bool rg){
	
	int nx, ny;
	vs[x][y] = 0;
	if(rg){
		for(int i = 0; i < 4; i++){
			nx = dx[i]+x;
			ny = dy[i]+y;
			if(nx >= 0 && ny >= 0 && ny < N && nx < N && vs[nx][ny] && B[nx][ny]== cur)
				dfs(nx, ny, rg);
		}
	}
	else{
		for(int i = 0; i < 4; i++){
			nx = dx[i]+x;
			ny = dy[i]+y;
			if(nx >= 0 && ny >= 0 && ny < N && nx < N && vs[nx][ny] && A[nx][ny]== cur)
				dfs(nx, ny, rg);
		}
	}
}

void solve(){
	
	cin >> N;
	string buff;
	int ansa=0, ansb=0;
	for(int i=0; i < N; i++){
		cin >> buff;
		for(int j = 0; j < N; j++){
			A[i][j] = buff[j];
			if(buff[j] == 'R') B[i][j] = 'G';
			else B[i][j] = buff[j];
		}
	}

	memset(vs, 1, sizeof(vs));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(vs[i][j]){
				ansa++;
				cur = A[i][j];
				dfs(i,j, 0);
			}
		}
	}	

	memset(vs, 1, sizeof(vs));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(vs[i][j]){
				ansb++;
				cur = B[i][j];
				dfs(i,j, 1);
			}
		}
	}	
	cout << ansa << ' ' << ansb;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}