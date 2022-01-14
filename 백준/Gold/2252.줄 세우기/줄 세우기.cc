#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unistd.h>

using namespace std;


void remove_number(vector<vector<int>> *a, vector<int> gijun, int rem){
    for(int index = 0; index < gijun.size(); index++) (*a)[gijun[index]].erase(remove((*a)[gijun[index]].begin(), (*a)[gijun[index]].end(), rem), (*a)[gijun[index]].end());
}



main(){
    
    int number, order, out;

    cin >> number >> order;

    vector<vector<int>> depends(number+1);
    vector<int> numbers(number+1);
    vector<vector<int>> record(number+1);

    fill(numbers.begin(), numbers.end(), -1);

    for(int i = 0; i < order; i++){
        int one, two;
        cin >> one >> two;
        depends[two].push_back(one);
        record[one].push_back(two);
    }

    out = 0;

    while(out != number){
        for(int i = 1; i < number+1; i++){
            if(numbers[i] == -1 && depends[i].size() == 0){
                cout << i << " ";
                numbers[i] = 1;
                remove_number(&depends, record[i], i);
                out ++;
            }
        }
    }
}