#include <bits/stdc++.h>
using namespace std;
int N, arr[1000000], s[1000000];
map <int, int> m;
void solve(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		s[i] = arr[i];
	}
	sort(s, s+N);
	int num = 0;
	m[s[0]] = num;
	num++;
	for(int i =1; i < N; i++){
		if(s[i]==s[0]) continue;
		if(!m[s[i]]){
			m[s[i]] = num;
			num++;
		}
	}
	for(int i = 0; i < N; i++){
		arr[i] = m[arr[i]];
	}
	for(int i = 0; i < N; i++){
		cout << arr[i] << ' ';
	}
	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}