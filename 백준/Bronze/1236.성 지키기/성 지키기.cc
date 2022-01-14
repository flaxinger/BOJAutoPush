#include <iostream>
#include <map>
using namespace std;

main(){
    char buffer[50], row[50], column[50];
    int n_row, n_col, i, j, r_count, c_count;

    cin >> n_row >> n_col;

    for(i = 0; i < n_row; i ++){
        row[i] = '.';
    }
    for(i = 0; i < n_col; i ++){
        column[i] = '.';
    }

    for(i = 0; i < n_row; i++){
        cin >> buffer;
        for(j = 0; j < n_col; j ++){
            if(buffer[j] == 'X'){
                row[i] = 'X';
                column[j] = 'X';
            }
        }
    }

    r_count = c_count = 0;
    for(i = 0; i < n_row; i++){
        if(row[i] == '.') r_count++;
    }
    for(i = 0; i < n_col; i++){
        if(column[i] == '.') c_count++;
    }

    if(c_count>r_count) cout << c_count;
    else cout << r_count;

}