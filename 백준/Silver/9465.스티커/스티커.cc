#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100010;
 
int r1[MAX], r2[MAX];
int sum1[MAX], sum2[MAX];
int f2(int n, int limit);

int f1(int n, int limit){
    if(n > limit) return 0;
    if(sum1[n]!=-1) return sum1[n];

    sum1[n] = max((r1[n]+r2[n+1]+f1(n+2, limit)),(r1[n]+r2[n+2]+f1(n+3, limit)));
    int temp = max((r1[n]+f2(n+1,limit)), (r1[n]+f2(n+2,limit)));
    sum1[n] = max(sum1[n], temp);
    return sum1[n];
}

int f2(int n, int limit){
    if(n > limit) return 0;
    if(sum2[n]!=-1) return sum2[n];

    sum2[n] = max((r2[n]+r1[n+1]+f2(n+2, limit)),(r2[n]+r1[n+2]+f2(n+3, limit)));
    int temp = max((r2[n]+f1(n+1,limit)), (r2[n]+f1(n+2,limit)));
    sum2[n] = max(sum2[n], temp);
    return sum2[n];
}
 
int main(){
    int count, N, i;
    scanf("%d", &count);

    for (int x = 0; x < count; x++){
        scanf("%d", &N);
        fill(sum1, sum1+N+4, -1);
        fill(sum2, sum2+N+4, -1);
        fill(r1, r1+N+4, 0);
        fill(r2, r2+N+4, 0);

        for(i = 1; i < N+1; i++){
            scanf("%d",&r1[i]);
        }
        for(i = 1; i < N+1; i++){
            scanf("%d",&r2[i]);
        }
        printf("%d\n", max(f1(1, N),f2(1, N))); 
     }
}


