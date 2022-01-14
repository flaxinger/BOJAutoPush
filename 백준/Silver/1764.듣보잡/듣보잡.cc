#include <bits/stdc++.h>
using namespace std;

map<string, bool> m;
int N, M;

void solve(){
	vector<string> names;
	
	cin >> N >> M;
	string buff;
	for(int i = 0; i < N; i++){
		cin >> buff;
		m[buff] = 1;
	}
	for(int i = 0; i < N; i++){
		cin >> buff;
		if(m[buff]) names.push_back(buff);
	}
	sort(names.begin(), names.end());
    int o = names.size();
	cout << o << '\n';
	for(int i =0; i < o; i++){
		cout << names[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}