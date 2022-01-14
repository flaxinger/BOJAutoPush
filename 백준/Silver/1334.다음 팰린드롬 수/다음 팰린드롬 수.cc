#include <bits/stdc++.h>
using namespace std;
string add(string str, int mid){
    bool passed = false;
    //cout << "in add: " +str + " mid: " + to_string(mid) << endl;
    if(str[mid-1]=='9'&&mid!=0){
        str = add(str, mid-1);
        passed = true;
    }
    if(mid == 0){
        for(int i = 0; i < str.length(); i++){
            str[i]='0';
        }
        str[0]= '1';
        str = str + '0';
    }
    else{
        for(int i = mid; i < str.length(); i++){
            str[i]='0';
        }
        if(!passed) str[mid-1]++;
        str[mid] = '0';  
    }     
    return str;
}
string solve(string a){
    int len, mid, left, right;
    bool inc = false;
    bool not_change = true;
    bool less = false;
    len = a.length()-1;
    mid = len/2;
    left = (len%2==1) ? mid : len/2-1;
    right = mid+1;
    //cout << left << ' ' << mid << ' ' << right << endl;
    //cout << "in solve: " << a << endl;
    while(left >= 0){
        if(!less && a[right] < a[left]) less = true;
        if(!less && a[left] < a[right]) inc = true;
        if(a[left] != a[right]) not_change = false;
        a[right] = a[left];
        left--;
        right++;
    }
    if(not_change || len == 0) inc = true;
    if(inc && len%2 == 1){  
        if(a[mid] == '9') a = solve(add(a, mid));
        else{
            a[mid]++;
            a[mid+1]++;    
        }
    }
    else if(inc && len%2 == 0){
        if(a[mid] == '9') a = solve(add(a, mid));
        else a[mid]++;  
    } 
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    cout << solve(a);
    return 0;
}