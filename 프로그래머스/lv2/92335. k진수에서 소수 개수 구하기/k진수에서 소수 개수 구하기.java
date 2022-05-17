import java.util.*;

class Solution {
    
    boolean[] isPrime = new boolean[1000001];
    
    public int solution(int n, int k) {
        int answer = 0;
        initIsPrime();
        List<String> candidate = new ArrayList<>();
        String cur = "";
        for(char c: toNary(n, k).toCharArray()){
            if(c == '0'){
                if(cur!="") candidate.add(cur);
                cur = "";
            }
            else cur+=c;
        }
        if(cur!="") candidate.add(cur);
        for(String can: candidate){
            if(Long.valueOf(can)>=1000001){
                if(isLongPrime(Long.valueOf(can)))
                    answer++;
            }
            else if(isPrime[Integer.valueOf(can)]){
                answer++;
            }
        }
        return answer;
    }
    
    public void initIsPrime(){
        
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < 1000001; i++){
            int nonP = i*2;
            while(nonP < 1000001){
                isPrime[nonP] = false;
                nonP+=i;
            }
        }
    }
    
    public boolean isLongPrime(long num){
        if(num%2 == 1){
            for(long i = 3; i < Math.sqrt(num)+1; i+=2){
                if((num%i)==0) return false;
            }
        }
        else{
            for(long i = 2; i < Math.sqrt(num)+1; i+=2){
                if((num%i)==0) return false;
            }
        }
        return true;
    }
    
    
    public String toNary(int n, int k){
        
        int div = 1;
        while(div < 1000001){
            div*=k;
        }
        
        String result = "";
        while(div >1){
            if(result.length() > 0 || n/div > 0){
                result+=String.valueOf(n/div);
            }
            n%=div;
            div/=k;
        }
        result+=String.valueOf(n/div);
        return result;
    }
}