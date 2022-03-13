import java.util.*;

class Solution {
    
    private Queue<Node> q;    
    private int answer, depth;
    private Map<Integer, ArrayList<Integer>> map;
    private boolean[] vs;
    
    public int solution(int n, int[][] edge) {
        answer = 0;
        q = new LinkedList<>();
        map = new HashMap<>();
        vs = new boolean[n+1];
        depth = 0;
        
        for(int[] pair: edge){
            map.putIfAbsent(pair[0], new ArrayList<>());
            map.putIfAbsent(pair[1], new ArrayList<>());
            map.get(pair[0]).add(pair[1]);
            map.get(pair[1]).add(pair[0]);
        }
        
        q.add(new Node(1, 0));
        vs[1] = true;
        while(!q.isEmpty()){
            bfs(q.poll());
        }
        return answer;
    }
    
    public void bfs(Node node){
        if(!map.containsKey(node.num)) return;
        if(node.depth > depth){
            answer = 0;
            depth = node.depth;
        }
        answer++;
        ArrayList<Integer> list = map.get(node.num);
        for(Integer n: list){
            if(!vs[n]){
                vs[n] = true;
                q.add(new Node(n, node.depth+1));
            }
        }
        
    }
    
    private class Node{
        int num, depth;
        Node(int num, int depth){
            this.num = num;
            this.depth = depth;
        }
        
        @Override
        public String toString(){
            return "["+this.num +", "+this.depth+"]";
        }
    }
}