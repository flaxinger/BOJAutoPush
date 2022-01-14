#include <iostream>

using namespace std;

main(){
    int a, b, result;
    cin >> a;
    int seat[100] = {0};

    result = 0;

    for(int i = 0; i < a; i++){
        cin >> b;

        if(seat[b-1]==0){
            seat[b-1]=1;
        }
        else result++;
    }

    cout << result;
}