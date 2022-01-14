#include <bits/stdc++.h>

using namespace std;

int cross[51];
int ln[51][4];
int pcd[51][2];
int adjst[4] = {0, -1, -1, 0};
int mult[4] = {0, 2, 3, 1};
int asas[51];
int ans;
int best;
int chk[2];

void solve(){

    int c, mx = 0;

    cin >> c;

    c/=2;

    for(int i = 0; i < c; i++){
        cin >> ln[i][0] >> ln[i][1] >> ln[i][2] >> ln[i][3];
        if(ln[i][1] > mx) mx = ln[i][1]; 
        if(ln[i][3] > mx) mx = ln[i][3];
        ln[i][0]--;
        ln[i][2]--;
    }

    mx++;
    adjst[2] *= mx;
    adjst[1] *= mx;

    for(int i = 0; i < c; i++){
        pcd[i][0] = mult[ln[i][0]] * mx + abs(ln[i][1] + adjst[ln[i][0]]);
        pcd[i][1] = mult[ln[i][2]] * mx + abs(ln[i][3] + adjst[ln[i][2]]);
    }

    // debug
    // for(int i = 0; i < c; i++){
    //     cout << pcd[i][0] << " " << pcd[i][1] << endl;
    // }

    int temp;
    for(int i = 0; i < c; i++){
        if(pcd[i][0] > pcd[i][1]){
            temp = pcd[i][0];
            pcd[i][0] = pcd[i][1];
            pcd[i][1] = temp;
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            memset(chk, 0, sizeof(chk));
            if(i!=j){
                //cout << "currently in " << i << " comparing " << j << endl;
                for(int k = 0; k < 2; k++){
                    if(pcd[i][0] > pcd[j][k] || pcd[i][1] < pcd[j][k])
                        chk[0]= true;    
                }
                for(int k = 0; k < 2; k++){
                    if(pcd[i][0] < pcd[j][k] && pcd[i][1] > pcd[j][k])
                        chk[1]= true;    
                }
                //cout << "\t" << chk[0] << ' ' << chk[1] << endl;
            }
            if(chk[0] && chk[1]){
                ans++;
                asas[i]++;
                //cout << i << " and " << j << " cross" << endl;
            }
        }
        if(asas[i] > best) best = asas[i];
    }

    cout << ans/2 << endl << best;

}



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();

    return 0;
}

