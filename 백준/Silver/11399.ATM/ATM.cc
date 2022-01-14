#include <bits/stdc++.h>
using namespace std;
int N, arr[1000];
int s[1000];
void solve(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	int ans = 0;
	for(int i = 0; i < N; i++){
		
		arr[i]+=arr[i-1];
		ans += arr[i];
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}