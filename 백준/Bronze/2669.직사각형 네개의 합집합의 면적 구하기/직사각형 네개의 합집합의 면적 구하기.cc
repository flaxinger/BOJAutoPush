#include <bits/stdc++.h>

using namespace std;

int chart[101][101];

void solve(){
    int y_low, x_low, y_high, x_high, sz = 0;
    
    for(int i = 0; i < 4; i++){
        cin >> y_low >> x_low >> y_high >> x_high;
        
        for(int j = x_high; j > x_low; j--)
            for(int k = y_high; k > y_low; k--)
                chart[j][k] = 1;
    }
    
    for(int j = 1; j < 101; j++)
        for(int k = 1; k < 101; k++)
            if(chart[j][k]) sz++;
            
    cout << sz << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();

    return 0;
}
