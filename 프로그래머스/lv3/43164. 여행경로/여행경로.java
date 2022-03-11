import java.util.*;

class Solution {
    
    private String[] ans;
    private String[][] tickets;
    private int N;
    private Map<String, List<Node>> map;
    private List<String> buff;
    
    public String[] solution(String[][] tickets) {
        this.tickets = tickets;
        this.ans = null;
        init();
        N = tickets.length;
        buff.add("ICN");
        dfs("ICN");
        return ans;
    }
    
    private void init(){
        map = new HashMap<>();
        buff = new ArrayList<>();
        for(String[] ticket: tickets){
            map.putIfAbsent(ticket[0], new ArrayList<>());
            map.get(ticket[0]).add(new Node(ticket[1], true));
        }
        for(Map.Entry<String, List<Node>> e: map.entrySet()){
            e.getValue().sort((a, b) -> a.name.compareTo(b.name));
        }
    }
    
    private class Node{
        String name;
        boolean use;
        
        Node(String name, boolean u){
            this.name = name;
            this.use = u;
        }
        
        @Override
        public String toString(){
            return name+", "+use;
        }
    }
    
    private void dfs(String node){
        if(ans!=null) return;
        if(buff.size() == N+1){
            ans = buff.toArray(new String[buff.size()]);
            return;
        }
        if(map.containsKey(node)){
            List<Node> list = map.get(node);
            for(Node n: list){
                if(n.use){
                    n.use = false;
                    buff.add(n.name);
                    dfs(n.name);
                    n.use = true;
                    buff.remove(buff.size()-1);
                }
            }
        }
    }
}