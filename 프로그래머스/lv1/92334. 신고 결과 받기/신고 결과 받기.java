import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, Set<String>> map = new HashMap<>();
        Map<String, Integer> pos = new HashMap<>();
        int cnt = 0;
        for(String id: id_list){
            pos.put(id, cnt++);
            map.put(id, new HashSet<>());
        }
        for(String r: report){
            String[] s = r.split(" ");
            map.get(s[1]).add(s[0]);
        }
        
        for(Map.Entry<String, Set<String>> e: map.entrySet()){
            if(e.getValue().size()>=k)
                for(String reporter: e.getValue())
                    answer[pos.get(reporter)]++;
            
        }
        return answer;
    }
}