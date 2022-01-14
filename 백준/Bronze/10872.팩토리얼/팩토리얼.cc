#include <iostream>

using namespace std;

int func(int x){
    
    if (x <= 1){
        return 1;
    }
    
    return x * func(x-1);
}

int main(){
    int a;
    cin >> a;
    
    cout << func(a); 
}