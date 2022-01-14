#include <bits/stdc++.h>
using namespace std;


void solve(){
    string board;
    int counter = 0;
    int start = 0;
    bool failed = false;
    cin >> board;

    for(int i = 0; i < board.length(); i++){
        if(board[i]=='X') counter++;
        
        if(board[i] == '.' || i == board.length()-1){
            int a = counter/4;
            int b = (counter-a*4)/2;

            //cout << start << ' ' << a << ' ' << b << endl;
            for(int j = start; j < start+a*4; j++){
                board[j] = 'A';
            }
            start += a*4;
            for(int j = start; j < start + b*2; j++){
                board[j] = 'B';
            }
            if(counter != a*4+b*2) failed = true;
            start = i+1;
            counter = 0;
        }
    }
    if (failed == true) cout << -1;
    else cout << board;
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}