#include <bits/stdc++.h>
using namespace std;

deque<string> dq;

string func(string buff, string cmd){

    dq.clear();
    string result = "";
    string b;
    int dir = 0;
    char bb;
    for(int i = 0; i < buff.length(); i++){
        b = "";
        bb = buff[i];
        // if(bb >= '0' && bb <='9'){
        int j = 0;
        while(bb >= '0' && bb <='9'){
            b += bb;
            buff[j+i]='a';
            j++;
            bb = buff[j+i];
        }
        if(b.length()) dq.push_back(b);
    }
    // while(!dq.empty()){
    //     result += dq.front()+" ";
    //     dq.pop_front();
    // }

    for(int i = 0; i < cmd.length(); i++){
        
        if(dq.empty() && cmd[i] == 'D') return "error";
        if(cmd[i] == 'R') dir++;
        else if(dir%2) dq.pop_back();
        else dq.pop_front();
    }

    result+="[";
    if(dir%2){
        while(!dq.empty()){
            result += dq.back();
            if(dq.size()!=1) result+=",";
            dq.pop_back();
        }
    }
    else{
        while(!dq.empty()){
            result += dq.front();
            if(dq.size()!=1) result+=",";
            dq.pop_front();
        }        
    }
    result+="]";
    return result;
}

void solve(){

    int N, cnt;
    string cmd, buff;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> cmd >> cnt >> buff;
        cout << func(buff, cmd) << endl;
    }    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
