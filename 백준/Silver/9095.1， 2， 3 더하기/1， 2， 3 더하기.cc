#include <bits/stdc++.h>
using namespace std;
int N;
int dp[12];

int func(int n){
	if(n==0) return 1;
	if(dp[n]) return dp[n];
	
	if(n-1 >= 0){
		dp[n] += func(n-1);
	}
	if(n-2 >= 0){
		dp[n] += func(n-2);
	}
	if(n-3 >= 0){
		dp[n] += func(n-3);
	}
	return dp[n];

}

void solve(){
	cin >> N;
	int buff;
	for(int i =0; i < N; i++){
		cin >> buff;
		cout << func(buff)<< endl;
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}