import java.util.*;

class Solution {
    
    int[] times;
    long N;
    public long solution(int n, int[] times) {
        this.times = times;
        this.N = n;
        
        long max = 0;
        for(int t: times){
            max = Math.max(max, t);
        }
        return find(0, max*n);
    }
    
    private long calc(long n){
        long result = 0;
        for(int t: times){
            result += n/t;
        }
        return result;
    }
    
    private long find(long s, long e){
        long mid;
        while(s<e){
            mid = (e+s)/2;
            if(calc(mid)<N)
                s = mid+1;
            else
                e = mid-1;
        }
        if(calc(s) < N){
            s++;
        }
        return s;
    }
}