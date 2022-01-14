#include <iostream>
#include <deque>
using namespace std;

int func(int num){

    int result=0;

    if(num>=1000){
        result += num / 1000;  
        result += num%1000/100*10;
        result += num%100/10*100;
        result += num%10*1000;
        return result;
    }
    else if(num >=100){
        result += num/100;
        result += num%100/10*10;
        result += num%10*100;
        return result;
    }
    else if(num >= 10){
        result += num/10;
        result += num%10*10;
        return result;
    }
    else return num;
}

main(){
    int a, b;

    cin >> a >> b;

    cout << func(func(a) + func(b));

}

