#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

string func(string a){
    if(a.length() < 3) return a;
    string temp = a.substr(1, a.length()-2);
    sort(temp.begin(), temp.end());
    return a[0]+temp+a[a.length()-1];

}

int factorial(int a){

    int result = 1;
    for(int i = 1; i <= a; i++){
        result *=i;
    }
    return result;
}

void resolve(){

    string ai = "";
    getline(cin, ai);

    //cout << "got here: " << ai << endl;
    bool cont = true;
    string word = "";
    unsigned int result = 1;
    for(auto x : ai){
        if(x == ' '){
            //cout << func(word) << endl;
            if(m.find(func(word)) != m.end()){
                result*=m[func(word)];
                cont = false;
            }
            word = "";
        }
        else{
            word+=x;
        }
    }
    //cout << func(word) << endl;
    if(m.find(func(word)) != m.end()){
        result*=m[func(word)];
        cont = false;
    }
    if(cont) cout << 0 << endl;
    else cout << result << endl;
}


void solve(){
    string buff1, buff2;
    int c;
    cin >> c;
    //cout << "got here";
    for(int i = 0; i < c; i++){
        cin >> buff1;
        buff2 = func(buff1);
        if(m.find(buff2) != m.end()){
            m[buff2]++;
            //cout << 1 << endl;
        }
        else{
            m[buff2] = 1;
            //cout << 2 << endl;
        }
    }
    //cout << "got here";
    cin >> c;
    cin.ignore(INT_MAX, '\n');
    for(int i = 0; i < c; i++){
        resolve();
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
   
    //string a;
    //getline(cin, a);
    //cout << a << endl;
    return 0;
}


