#include <bits/stdc++.h>

using namespace std;

vector<int> x, y;

int track[10];
struct card{
    char type;
    int number;
};

card deck[5];


bool comp(card a, card b){
    if(a.type!=b.type)
        return (a.type < b.type);
    return a.number < b.number;
}

void calc(){

    bool yes = true;

    for(int i = 0; i < 5; i++){
        track[deck[i].number]++;
    }

    for(int i = 0; i < 4; i++){
        if(deck[i].type != deck[i+1].type || deck[i].number +1 != deck[i+1].number) yes = false;
    }
    if(yes){
        cout << 900+deck[4].number;
        return;
    }



    for(int i = 1; i < 10; i++){
        if(track[i] == 4){
            cout << 800 + i;
            return;
        }
    }

    for(int i = 1; i < 10; i++){
        if(track[i] == 3){
            for(int j = 1; j < 10; j++){
                if(track[j] == 2){
                    cout << 700 + i * 10 + j;
                    return;
                }
            }
        }
    }

    yes = true;
    for(int i = 0; i < 4; i++){
        if(deck[i].type!= deck[i+1].type) yes = false;
    }
    if(yes){
        cout << 600 + deck[4].number;
        return;
    }

    yes = true;
    for(int i = 1; i < 10; i++){
        if(track[i] == 1){
            for(int j = 1; j < 5; j++){
                if(track[i+j] != 1) yes = false;
            }   
            if(yes){
                cout << 500 + i+4;
                return;
            }
            break; 
        }
        
    }

    for(int i = 1; i < 10; i++){
        if(track[i] == 3){
            cout << 400 + i;
            return;
        }
    }

    for(int i = 1; i < 10; i++){
        if(track[i] == 2){
            for(int j = i+1; j < 10; j++){
                if(track[j] == 2){
                    cout << 300 + j * 10 + i;
                    return;
                }
            }
        }
    }

    for(int i = 1; i < 10; i++){
        if(track[i] == 2){
            cout << 200 + i;
            return;
        }
    }

    for(int i = 9; i > 0; i--){
        if(track[i] > 0){
            cout << 100 + i;
            break;
        }
    }
}


void solve(){

    for(int i = 0; i < 5; i++){
        cin >> deck[i].type >> deck[i].number;
    }

    sort(deck, deck+5, comp);

    calc();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
    return 0;
}