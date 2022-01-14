#include <bits/stdc++.h>

using namespace std;
int N, ans;

int arr[3];

//한 변의 크기
bool func(int a, int b, int c){
    if(a + b > c && a + c > b && b + c > a) return true;
    return false;
}
void solve(){
    cin >> N;
    arr[2] = 1;

    while(N - arr[2]*2 >= arr[2]){

        arr[0] = N - arr[2]*2;
        arr[1] = arr[2];

        while(arr[0] >= arr[1]){
            ans+=func(arr[0], arr[1], arr[2]);
            //cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
            
            arr[1]++;
            arr[0]--;
        }
        arr[2]++;
    }
    //cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
    cout << ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}