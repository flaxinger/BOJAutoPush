import java.util.*;

class Solution {
    
    Map<Integer, Integer> translationTable = new HashMap<>();
    List<Edge>[] graph;
    boolean[][] vs;
    int TARGET;
    PriorityQueue<Step> pq = new PriorityQueue<Step>((a, b)->Integer.compare(a.cost, b.cost));
    
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        
        TARGET = end;
        for(int i = 0; i < traps.length; i++){
            translationTable.put(traps[i], i);
        }
        graph = new ArrayList[n+1];
        vs = new boolean[n+1][1<<(traps.length+1)];
        for(int i = 1; i <= n; i++)
            graph[i] = new ArrayList<>();
        for(int[] road: roads){
            graph[road[0]].add(new Edge(road[1], road[2], false));
            if(translationTable.containsKey(road[1]) || 
               translationTable.containsKey(road[0]) ){
                graph[road[1]].add(new Edge(road[0], road[2], true));
            }
        }
        pq.add(new Step(start, 0, 0));
        return bfs();
    }
    
    private int bfs(){
        
        while(!pq.isEmpty() && pq.peek().node!=TARGET){
            Step cur = pq.poll();
            if(vs[cur.node][cur.state]) continue;
            vs[cur.node][cur.state] = true;
            for(Edge e: graph[cur.node]){
                if(!translationTable.containsKey(e.node) && !translationTable.containsKey(cur.node)){
                    pq.add(new Step(e.node, e.cost+cur.cost, cur.state));
                }
                else{
                    boolean isReverse = false;
                    if(translationTable.containsKey(e.node) && (cur.state&1<<translationTable.get(e.node)) > 0)
                        isReverse = !isReverse;
                    if(translationTable.containsKey(cur.node) && (cur.state&1<<translationTable.get(cur.node)) > 0){
                        isReverse = !isReverse;
                    }
                    if(isReverse == e.reverse){
                        int newState = cur.state;
                        if(translationTable.containsKey(e.node)){
                            if((cur.state&1<<translationTable.get(e.node)) > 0){
                                newState&=~(1<<translationTable.get(e.node));
                            }
                            else{
                                newState|=1<<translationTable.get(e.node);
                            }
                        }
                        pq.add(new Step(e.node, e.cost+cur.cost, newState));
                    }
                }
            }
        }
        return pq.peek().cost;
    }
    
    
    class Edge{
        int node, cost;
        boolean reverse;
        Edge(int node, int cost, boolean reverse){
            this.node = node;
            this.cost = cost;
            this.reverse = reverse;
        }
    }
    
    class Step{
        int node, cost, state;
        Step(int node, int cost, int state){
            this.node = node;
            this.cost = cost;
            this.state = state;
        }
    }
}