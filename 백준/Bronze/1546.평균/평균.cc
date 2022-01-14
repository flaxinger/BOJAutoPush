#include <iostream>
#include <map>
using namespace std;

main(){

    float buffer, max, sum;
    int input, i;
    cin >> input;

    float result[input];

    max = 0;
    for(i = 0; i < input; i++){
        cin >> buffer;
        if(buffer > max) max = buffer;
        result[i]= buffer;
    }


    sum = 0;
    for(i = 0; i < input; i++){
        if(max !=0)sum += result[i];
    }

    cout << sum/input/max*100;

}