#include <bits/stdc++.h>
using namespace std;

int DIV = 9901;

int cost[10], money, n, _min, rest_min;
string best;
char character[10];


void add_cost(int idx, int cost_param){
    for(int i = 0; i < n; i++){
        if(cost[i] == cost_param){
            character[i] = '0'+idx;
            n--;
            return;
        }
        if(cost[i] == -1){
            cost[i] = cost_param;
            character[i] = '0'+idx;
            if(cost[i] < _min){
                _min = cost[i];
                rest_min = i;  
            } 
            return;
        }
    }

}

void solve(){
    int number = 0;
    cin >> number;
    n = number;
    rest_min = 999999;
    _min = 10000;
    int aaa;
    fill(cost, cost+10, -1);
    for(int i = 0; i < number; i++){
        cin >> aaa; 
        add_cost(i, aaa);
    }

    cin >> money;
    
    bool check = true;
    for(int i = 0; i < n; i++){
        if(cost[i] <= money && character[i] != '0') check = false;
    }

    if(check){
        cout << '0';
        return;  
    } 

    int first_min = 999999;
    int first_idx = 0;
    for(int i = 0; i < n; i++){
        if(cost[i] < first_min && character[i] != '0'){
            first_min = cost[i];
            first_idx=i;
        }
    }

    string result;
    result+=character[first_idx];
    money -= first_min;

    while(_min <= money){
        result += character[rest_min];
        money -= _min;
    }
    //cout << _min << endl << character[first_idx] <<  character[rest_min] << endl << result << endl;

    int solve_idx = 0;
    int solve_len = result.length();
    int final_call = rest_min;
    while(money > 0 && solve_idx < solve_len){
        
        final_call = (solve_idx != 0) ? (_min) : (first_min);
        money += final_call;
        //cout << "currently in idx: " << solve_idx << " result is " << result << " final_call is: " << final_call << endl;
        for(int i = 0; i < n; i++){
            if(solve_idx == 0 && character[i] == '0') continue;
            if(result[solve_idx] < character[i] && money >= cost[i]){
                result[solve_idx] = character[i];
                
                final_call = cost[i]; 
            }
        }
        money -=final_call;
        solve_idx++;
    }

    cout << result;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}

