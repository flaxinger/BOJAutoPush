#include<iostream>
#include<cstdio>
#include<cstring>
#define MIN(a,b) (a<b ? a : b)
using namespace std;

int min_cnt = 0x3f3f3f3f, num_int;
int btn_set[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

void find(string num) {
    for(int i=0;i<10;i++) {
	    if(btn_set[i]) {
	        string tmp_num = num + to_string(i);
	        min_cnt = MIN(min_cnt, abs(num_int - stoi(tmp_num)) + tmp_num.length());

    	    if(tmp_num.length() < 6) {
	    	    find(tmp_num);
	        }
	    }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &num_int, &n);
    min_cnt = MIN(min_cnt, abs(100 - num_int));

    for(int i=0;i<n;i++) {
    	scanf("%d", &k);
	    btn_set[k] = 0;
    }

    if(n<10) {
	    find("");
    }

    printf("%d", min_cnt);
}
