#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	
	string cmd;
	int num, arr= 0;
	while(N--){
		cin >> cmd;
		if(cmd != "all" && cmd != "empty") cin >> num;
		if(cmd == "add"){
			arr |= 1 << num;
		}
		if(cmd == "remove"){
			arr &= ~(1 << num);
		}
		if(cmd == "check"){
			if(arr&1<<num) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if(cmd == "toggle"){
			if(arr&1<<num) arr &= ~(1 << num);
			else arr |= 1 << num;
		}
		if(cmd == "all"){
			arr = 2097151;
		}
		if(cmd == "empty"){
			arr = 0;
		}
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	// int a = 0;
	// for(int i = 0; i <= 20; i++){
	// 	a |= 1 << i;
	// }
	// cout << a;
	return 0;
}