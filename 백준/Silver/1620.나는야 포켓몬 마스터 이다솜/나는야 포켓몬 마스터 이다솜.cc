#include <bits/stdc++.h>
using namespace std;

map<string, string> M;
int A, B;

void solve(){

	cin >> A >> B;

	string buff, tmp;
	for(int i = 0; i < A; i++){
		cin >> buff;
		tmp = to_string(i+1);
		M[tmp] = buff;
		M[buff] = tmp;
	}
	
	for(int i = 0; i < B; i++){
		cin >> buff;
		cout << M[buff] << '\n';
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}