#include <iostream>

using namespace std;

intmax_t calculate_fib(intmax_t one, intmax_t two, intmax_t num){
    if(num == 2) return one + two;
    //cout << one << "\t" << two << "\t" << num << endl;
    return calculate_fib(two, one+two, num-1);
}


intmax_t fib(intmax_t num){
    
    if(num == 0) return 0;
    if(num == 1) return 1;
    
    return calculate_fib(0,1,num);
}



int main(){
    
    intmax_t num;
    
    cin >> num;
    
    cout << fib(num);
    
}