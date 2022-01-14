#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 
using namespace std;
 
int main()
{
    int count, buff;
    vector<int> a;
    
    cin >> count;
    
    for(int i = 0; i < count; i++){
        cin >> buff;
        if(std::find(a.begin(), a.end(), buff) == a.end()){
            a.push_back(buff);
            //cout << "wtf" << endl;
        }
    }
    
    std::sort(a.begin(), a.end(), std::less<int>());
    
    for(int i = 0; i < a.size(); i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}