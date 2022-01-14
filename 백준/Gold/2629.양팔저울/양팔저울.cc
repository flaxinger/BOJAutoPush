#include <iostream>
#include <vector>
using namespace std;

int weight_count, req_count;
int weights[31];
bool dp[31][15001] = {};

void getWeight(int idx, int weight){
    if(idx > weight_count) return;
    if(dp[idx][weight] > 0) return;

    dp[idx][weight] = 1;

    getWeight(idx + 1, weight);
    getWeight(idx + 1, weight + weights[idx]);
    getWeight(idx + 1, abs(weight - weights[idx]));
}

int main(){
    cin >> weight_count;
    for (int i = 0; i < weight_count; i++)
        cin >> weights[i];

    getWeight(0, 0);

    cin >> req_count;
    for (int n; req_count--; ){
        cin >> n;
        cout << (n > weight_count * 500 ? "N " : (dp[weight_count][n] ? "Y " : "N "));
    }
}