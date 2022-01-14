#include <bits/stdc++.h>

using namespace std;

int arr[10000];

bool func(int n){
    string a = to_string(n);
    string imp = a;
    char temp;

    for(int i = 0; i < 4; i++){
        if(a[i]=='0') return false;
    }

    for(int j = 0; j < 4; j++){

        temp = imp[3];
        imp[3] = imp[2];
        imp[2] = imp[1];
        imp[1] = imp[0];
        imp[0] = temp;

        if(stoi(imp) < n) return false;
    }

    return true;
}

void solve(){

    int idx = 1;
    for(int i = 1111; i < 10000; i++){
        if(func(i)){
            arr[idx] = i;
            idx++;
        }
    }
    string imp ="9999";
    int asas = stoi(imp);
    int buff[4];
    int temp = 0;
    for(int i = 0; i < 4; i++) cin >> buff[i];    

    for(int j = 0; j < 4; j++){

        temp = buff[3];
        buff[3] = buff[2];
        buff[2] = buff[1];
        buff[1] = buff[0];
        buff[0] = temp;


        //for(int i = 0; i < 4; i++) cout << buff[i];
        // cout << endl;
        for(int i = 0; i < 4; i++){
            imp[i] = buff[i]+'0';
        }

        if(stoi(imp) < asas) asas = stoi(imp);
    }

    

    
    for(int i = 0; i < 10000; i++){
        if(arr[i] == asas){
            cout << i;
            break;
        }
    }

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();

    return 0;
}

