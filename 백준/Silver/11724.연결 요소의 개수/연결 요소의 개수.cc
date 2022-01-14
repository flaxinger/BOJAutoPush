#include <bits/stdc++.h>
using namespace std;

int V, E, ans;
vector<int> edges[1001];
bool vs[1001];

void dfs(int idx){
	
	if(vs[idx]) return;
	vs[idx] = 1;
	vector<int>& conn = edges[idx];
	for(int i = 0; i < conn.size(); i++){
		dfs(conn[i]);
	}
}

void solve(){
	
	cin >> V >> E;
	int a, b;
	for(int i = 0; i < E; i++){
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	for(int i = 1; i <= V; i++){
		if(!vs[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}

int main() {
	// your code goes here
	solve();
	return 0;
}