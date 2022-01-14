#include <iostream>
#include <string.h>
using namespace std;



int func(int *num, int month){

    int result = 0; 

    for(int i = 0; i < month; i++){
        result+=num[i];
    }
    return result;
}

main(){
    int a, b;

    cin >> a >> b;

    int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    a = func(arr, a) + b;
    a = a%7;
    
    if(a == 1) cout << "MON";
    else if(a == 2) cout << "TUE";
    else if(a == 3) cout << "WED";
    else if(a == 4) cout << "THU";
    else if(a == 5) cout << "FRI";
    else if(a == 6) cout << "SAT";
    else cout << "SUN";
}

