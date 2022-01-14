#include <iostream>
using namespace std;

#define DIV 9901

int arr[2][3];
int n;
bool top = false;

void find(int idx){

    if(idx >= n) return;

    if(!top){
        arr[1][0] = (arr[0][0] + arr[0][1] + arr[0][2])% DIV;
        arr[1][1] = (arr[0][0] + arr[0][2]) % DIV;
        arr[1][2] = (arr[0][0] + arr[0][1]) % DIV;
        //cout << idx << ": " << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << "\n";
        top = true;
    }
    else{
        arr[0][0] = (arr[1][0] + arr[1][1] + arr[1][2])% DIV;
        arr[0][1] = (arr[1][0] + arr[1][2]) % DIV;
        arr[0][2] = (arr[1][0] + arr[1][1]) % DIV;
        //cout << idx << ": " << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << "\n";
        top = false;
    }

    find(idx+1);
}

void solve(){
    cin >> n;
    
    //fill(&arr[0][0], &arr[0][0]+, 100);

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;

    find(1);

    if(!top) cout << (arr[0][0] + arr[0][1] + arr[0][2])%DIV;
    else cout << (arr[1][0] + arr[1][1] + arr[1][2])%DIV;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

