#include <bits/stdc++.h>

#define done_using -1

using namespace std;

int crane[50];
int idx[50];
int boxes[10000];
int crane_n, box_n, boxes_loaded, result;

void increment(){

    for(int i = 0; i < crane_n; i++){
        while(idx[i] < box_n && boxes[idx[i]] == -1) idx[i]++;
        if(idx[i] != box_n){
            boxes[idx[i]] = -1;
            boxes_loaded++;    
        }
        //for(int i = 0; i < box_n; i++) cout << boxes[i] << " ";
        //cout << endl;
    }

    result++;
}



void solve(){
    
    cin >> crane_n;
    for(int i = 0; i < crane_n; i++) cin >> crane[i];
    cin >> box_n;
    for(int i = 0; i < box_n; i++) cin >> boxes[i];
    
    sort(crane, crane+crane_n, greater<int>());
    sort(boxes, boxes+box_n, greater<int>());
    
    for(int i = 0; i < crane_n; i++){
        for(int j = 0; j <= box_n; j++){
            if(crane[i] >= boxes[j]){
                idx[i] = j;
                break;
            }
        }
    }

    boxes_loaded = 0;
    result = 0;

    if(idx[0] != 0){
        cout << -1;
        return;
    }

    while(boxes_loaded < box_n){
        increment();
        //cout << "LOADED " << boxes_loaded << " THIS ROUND" << "\n";
        
    }

    cout << result;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}

