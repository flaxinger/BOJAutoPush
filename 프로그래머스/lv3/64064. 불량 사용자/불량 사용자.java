import java.util.*;
class Solution {
    
    Map<String, Integer> stringTable;
    Map<String, Boolean> vs;
    List<String>[] map;
    int N;
    Set<Integer> record;
    public int solution(String[] userIds, String[] bannedIds) {
        record = new HashSet<>();
        N = bannedIds.length;
        stringTable = new HashMap<>();
        vs = new HashMap<>();
        for(int i = 0; i < userIds.length; i++){
            stringTable.put(userIds[i], i);
            vs.put(userIds[i], false);
        }
        map = new ArrayList[N];
        for(int i =0; i < N; i++){
            String pattern = bannedIds[i].replace('*', '.');
            map[i] = new ArrayList<>();
            for(String userId: userIds){
                if(userId.matches(pattern)){
                    map[i].add(userId);
                }
            }
        }
        dfs(0, 0);      
        return record.size();
    }
    
    private void dfs(int node, int state){
        if(node==N){
            record.add(state);
            return;
        }
        ArrayList<String> curVs = new ArrayList<>();
        for(String s: map[node]){
            if(!vs.get(s)){
                vs.put(s, true);
                curVs.add(s);
                dfs(node+1, state|1<<stringTable.get(s));
                vs.put(s, false);
            }
        }
    }
}