#include <iostream>
#include <cstdint>
using namespace std;

bool check(int num){
    for(int j = 2; j <=num/2; j ++){
        if (num%j == 0) return false;
    }
    return true;
}

int main(){
    int in_first, in_second, counter, min;
    intmax_t sum;
    int out[10000];
    counter = 0;

    cin >> in_first >> in_second;
    if (in_first == 1) in_first =2;
    for (int i = in_first; i <= in_second; i ++){
        if(check(i)){
            out[counter] = i;
            counter ++;
        }
    }
    
    sum =0;
    min = -1;
    
    for (int i = 0; i < counter; i++){
         sum += out[i];
    }

    if (sum ==0){
        cout << min;
    }else cout << sum << endl << out[0];
    
}