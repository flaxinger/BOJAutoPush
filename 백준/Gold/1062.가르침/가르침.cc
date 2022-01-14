#include <bits/stdc++.h>

using namespace std;

int N, K, ans, ans_count, sm, alphabets, ii = 1;
vector<int> words;
int arr[150];

int shorten(string a){
    int result = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != 'a' && a[i]!= 'n' && a[i] != 't' && a[i]!= 'i' && a[i]!='c'){
            if(arr[a[i]]!=0) result |= 1 << arr[a[i]];
            else{
                arr[a[i]] = ii;
                ii++;
                result |= 1 << arr[a[i]];
            }
            //cout << arr[a[i]] << endl;
        }
    }
    alphabets |= result;
    return result;
}

void func(int idx){
	//cout << idx << endl;
	ans_count = 0;
	for(int i = 0; i < N; i++){
		if(idx == (idx|words[i])) ans_count++;
	}
	if(ans_count > ans) ans = ans_count;
}

void solve(){

    string tmp;
    int sh, tot, sum_tmp, cost_tmp;
    cin >> N >> K;
    K-=5;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        sh = shorten(tmp);
        tot = 0;
        for(int i = 0; i < ii; i++){
            if(sh&1<<i){
                tot++;
            }
        }
        if(tot <= K){
            words.push_back(sh);
        }
    }
    N = words.size();
    //cout << ii << endl;
    for(int i = 0; i <= 1<<ii; i++){
    	sm = 0;
    	for(int j = 0; j < ii; j++)
    		if(i&1<<j) sm++;
    	//cout << sm << endl;
    	if(sm <= K) func(i);
    	
    }
   	//func(0);
    cout << ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    //printf("%d", 'z');
    return 0;
}

