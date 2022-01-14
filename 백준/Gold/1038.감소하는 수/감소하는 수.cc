#include <bits/stdc++.h>

using namespace std;

int target, cnt, pointer;
string a = "0";

void func(){
    if(a.length() == 11){
        cout << -1;
        return;
    }
    if(cnt == target){
        cout << a;
        return;
    } 
    cnt++;
    if(a.length() == 1){
        if(a[0] < '9'){
            a[0]++;
            func();
            return;
        }
        else{
            a = "10";
            func();
            return;
        }
    }
    else{
        for(int i = a.length()-1; i > 0; i--){
            if(a[i]+1 < a[i-1]){
                a[i]++;
                for(int j = i+1; j < a.length(); j++) a[j] = '0' + a.length() - j - 1;
                func();
                return;
            } 
        }
        if(a[0] != '9'){
            a[0]++;
            for(int j = 1; j <= a.length(); j++) a[j] = '0' + a.length() - j -1;
            func();
            return;
        } 
        else{
            a = a+'0';
            for(int j = 0; j <= a.length(); j++) a[j] = '0' + a.length() - j -1;
            func();
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> target;
    func();
    return 0;
}


