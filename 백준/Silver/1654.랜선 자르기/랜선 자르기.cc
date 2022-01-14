#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int check(vector<int> *a, int num, int target){
    int sum = 0;
    for(int i = 0; i < (*a).size(); i++){
        sum += (*a)[i]/num;
    }
    return sum;
}

int get_max(vector<int> *a){
    int max = 0;
    for(int i = 0; i < (*a).size(); i++){
        if((*a)[i] > max) max = (*a)[i]; 
    }
    return max;
}

int main(){
    int c, target_num, buff;
    vector<int> a;
    
    cin >> c >> target_num;

    for(int i = 0; i < c; i++){

        cin >> buff;
        a.push_back(buff);
    }
    int max = get_max(&a);

    int start = 0;
    bool go_on = true;
    while(start + 1< max){
        int mid = ((long long)start + (long long)max) /2;
        
        if(check(&a, mid, target_num)>=target_num) start = mid;
        else max = mid;
    }
    
    if(target_num <= check(&a, max, target_num)) start = max;
    cout << start;
}



