#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int num, i;
    deque<char> left, right;
    cin >> s >> num;

    for(i = 0; i < s.size(); i++){
        left.push_back(s[i]);
    }

    for(i = 0; i < num; i++){
        string buff;
        cin >> buff;
        char temp;
        if(buff[0] == 'L' && left.size() > 0){
            right.push_back(left.back());
            left.pop_back();
        }
        else if(buff[0] == 'D' && right.size() > 0){
            left.push_back(right.back());
            right.pop_back();   
        }
        else if(buff[0] == 'B' && left.size() > 0) left.pop_back();
        else if(buff[0] == 'P'){
            char a;
            cin >> a;
            left.push_back(a);
        }
    }


    while(left.size()>0){
        cout << left.front();
        left.pop_front();
    }
    
    while(right.size()>0){
        cout << right.back();
        right.pop_back();
    }
}