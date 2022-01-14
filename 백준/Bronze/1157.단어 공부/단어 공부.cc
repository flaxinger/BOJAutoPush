#include <iostream>
#include <map>
using namespace std;

main(){
    char buffer[1000000];
    map<char,int> count;
    int index, max;
    char ans;
    index = max = 0;
    ans = '?';
    cin >> buffer;

    while(buffer[index]!='\0'){
        count[(char)toupper(buffer[index])]++;
        index++;
    }

    for(auto item : count){
        if(item.second > max){
            max = item.second;
            ans = item.first;  
        } 
        else if(item.second == max){
            ans = '?';
        }
    }
    
    if (ans!='?') cout << ans;
    else cout << ans;

}