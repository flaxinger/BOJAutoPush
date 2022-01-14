#include <iostream>

using namespace std;

int arr[40] = {0};
int zero_arr[40] = {0};
int one_arr[40] = {0};


int fibonacci(int n, int *zero, int *one) {
    if (n == 0) {
        *zero+=1;
        return 0;
    } else if (n == 1) {
        *one+=1;
        return 1;
    } else if(arr[n]!=0){
        *zero += zero_arr[n];
        *one += one_arr[n];
        return arr[n];
    }
    else {
        int inside_one=0;
        int inside_zero=0;
        arr[n] = fibonacci(n-1, &inside_zero, &inside_one) + fibonacci(n-2, &inside_zero, &inside_one);
        *one +=inside_one;
        *zero +=inside_zero;
        zero_arr[n] = inside_zero;
        one_arr[n] = inside_one;
        return arr[n];
    }
}


int main(){
    int count, buffer, zeros, ones;
    
    
    cin >> count;
    
    for(int i = 0; i < count; i++){
        ones = zeros = 0;
        cin >> buffer;
        int dummy = fibonacci(buffer, &zeros, &ones);
        printf("%d %d\n", zeros, ones);
    }
}



