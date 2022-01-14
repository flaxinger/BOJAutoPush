#include <bits/stdc++.h>

using namespace std;

int n, m;
int sw[101];
int gender[101];
int sn[101];

void click(int idx){
    if(sw[idx]) sw[idx] = 0;
    else sw[idx] = 1;
}

void mclick(int idx){

    int mul = 1;

    while(mul*idx <= n){
        click(idx*mul);
        mul++;
    }
}   

void fclick(int idx, int range){
    //cout << "range is " << range << endl;
    if(range == 0){
        click(idx);
        fclick(idx, range+1);  
    } 
    else if(idx - range > 0 && idx + range <= n && sw[idx+range] == sw[idx-range]){
        click(idx+range);
        click(idx-range);
        fclick(idx, range+1);
    }

}
void solve(){
    cin >> n;

    for(int i = 1; i <=n; i++){
        cin >> sw[i];
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> gender[i] >> sn[i];
        gender[i]--;
    }

    for(int i = 0; i < m; i++){
        if(gender[i]) fclick(sn[i], 0);
        else mclick(sn[i]);
    }

    for(int i = 1; i <= n; i++){
        cout << sw[i] << ' ';
        if(i%20 == 0) cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}