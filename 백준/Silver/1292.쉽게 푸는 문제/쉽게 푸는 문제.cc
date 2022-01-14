#include <iostream>

using namespace std;

int main()
{
    int arr[1000];
    int temp, check, i, start, end, sum;
    
    check = temp = 0;
    
    for (i = 0; i < 1000; i++){
        if(check == temp){
            check = 0;
            temp++;
        }
        
        arr[i] = temp;
        check ++;
    }
    
    cin >> start >> end;
    sum = 0;
    
    for(i = start-1; i <= end-1; i++){
        sum += arr[i];
    }
    
    cout << sum << endl;
    
    //for(i = 0; i < 100; i++){
    //    cout << '[' << i+1 << "]" << arr[i]<< " ";
    //}
    //cout << endl;
}
