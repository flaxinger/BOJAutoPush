#include <iostream>
#include <vector>

using namespace std;

int main(){

    int a, b, c, ans, counter;

    cin >> a >> b >> c;

    b--;
    c--;
    counter = 1;
    while(a+1/2 > 1){
        //printf("b is %d, c is %d, half is %d, %d\n", b, c, b/2, c/2);
        if(b/2 == c/2){
            ans = counter;  
            break;
        } 
        b/=2;
        c/=2;
        a/=2;
        counter++;
    }

    cout << counter;

    return 0;
}