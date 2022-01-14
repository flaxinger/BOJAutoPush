#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> arr[100000];

void solve(){
	
	cin >> N;
	int buff1, buff2;
	for(int i =0; i < N; i++){
		cin >> buff2 >> buff1;
		arr[i] = {buff1, buff2};
	}
	
	sort(arr, arr+N);
	
	int start = 0, end = 0, ans = 0;
	for(int i = 0; i < N; i++){
		if(arr[i].second >=end){
			end = arr[i].first;
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