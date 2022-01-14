#include <iostream>
#include <map>
#include <cmath>

using namespace std;


bool check(int a){
    int length = 0;
    int division = 1;
    for(int i = 0; i < 5; i++){
        if(a/division == 0 ){
            break;
        }
        division = division * 10;
        length ++;
    }
    length--;
    if(length >= 3){
        if(a/(int)pow(10,length) != a%10/1) return false;
        if(a%(int)pow(10,length)/(int)pow(10,length-1) != a%100/10) return false;
    }
    else if(length >= 1){
        if(a/(int)pow(10,length) != a%10/1) return false;
    }
    return true;
}

main(){

    int buffer, index;
    int result[100000];

    index = 0;
    buffer = 1;

    while(buffer!=0){
        cin >> buffer;
        
        result[index] = check(buffer);
        index++;
    }

    for(int i = 0; i < index-1; i++){
        if(result[i] == 1) cout << "yes" << endl;
        else cout << "no" << endl;
    }


}