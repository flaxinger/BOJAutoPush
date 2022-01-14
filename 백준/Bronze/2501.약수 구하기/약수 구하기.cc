#include <iostream>
#include <climits>

using namespace std;

int main(){
    long count, a, b;
    long list[1000000];
    
    cin >> a >> b;
    
    count = 0;
    
    for(long i = 1; i <= a; i++){
        if(a%i == 0){
            list[count] = i;
            count ++;
        }
    }
    
    if (b <= count){
        cout << list[b-1];
    }
    else {
        cout << 0;
    }
    return 0;
}