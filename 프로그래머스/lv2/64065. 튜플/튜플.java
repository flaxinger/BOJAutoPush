import java.util.*;

class Solution {
    
    Map<String, Integer> map;
    
    public int[] solution(String s) {
        map = new HashMap<>();
        parse(s);
        int[] answer = new int[map.size()];
        
        for(Map.Entry<String, Integer> set: map.entrySet()){
            answer[map.size()-set.getValue()] = Integer.valueOf(set.getKey());
        }
        return answer;
    }
    
    private void parse(String s){
        char c;
        String buff = "";
        for(int i = 0; i < s.length(); i++){
            c = s.charAt(i);
            if(isChar(c)){
                buff+=c;
            }
            else if(buff!=""){
                map.putIfAbsent(buff, 0);
                map.put(buff, map.get(buff)+1);
                buff = "";
            }
        }
    }
    
    private boolean isChar(char c){
        if(c>='0'&&c<='9')
            return true;
        return false;
    }
}