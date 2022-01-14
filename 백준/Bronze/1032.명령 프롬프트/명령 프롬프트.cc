#include <iostream>

using namespace std;

main(){
    int i, input, index;
    char buffer[50], result[50];

    cin >> input;
    cin >> result;

    for(i=0; i<input-1; i++){
        cin >> buffer;
        index = 0;

        while(result[index]!='\0'){
            if(buffer[index]!=result[index]){
                result[index]='?';
            }
            index++;
        }
    }    
    cout << result;
}