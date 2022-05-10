import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int N = gems.length;
        int[] ans = new int[]{1, N};
        Map<String, Integer> map = new HashMap<>();
        
        for(String gem: gems){
            map.putIfAbsent(gem, 0);
        }
       
        int size = map.values().size()-1;
        map.put(gems[0], 1);
        int left = 0, right = 0;
        
        while(left<N){
            if(right<N-1 && size>0){
                right++;
                if(map.get(gems[right])== 0){
                    size--;
                }
                map.put(gems[right], map.get(gems[right])+1);
            }
            else{
                if(size == 0){
                    if((ans[1]-ans[0]) > (right-left)){
                        ans[0] = left+1;
                        ans[1] = right+1;
                    }
                }
                map.put(gems[left], map.get(gems[left])-1);
                if(map.get(gems[left])== 0){
                    size++;
                }
                left++;              
            }
        }
        return ans;
    }
}