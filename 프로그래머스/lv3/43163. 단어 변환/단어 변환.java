import java.util.*;
class Solution {
    
    private int ans, N, WN;
    private boolean[][] graph, vs;
    private int begin, target;
    
    public int solution(String begin, String target, String[] words) {
        
        List<String> wTemp = new ArrayList<>();
        int bT=0, tT=0;
        for(String w: words){
            if(w.equals(target))
                tT = 1;
            if(w.equals(begin))
                bT = 1;
            wTemp.add(w);
        }        
        if(bT == 0) wTemp.add(begin);
        if(tT == 0) wTemp.add(target);
        words = wTemp.toArray(new String[wTemp.size()]);
        
        this.ans = Integer.MAX_VALUE;
        this.N = words.length;
        this.WN = words[0].length();
        this.graph = new boolean[N][N];
        this.vs = new boolean[N][N];

        
        for(int i = 0;i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist(words[i], words[j]) == 1){
                    graph[i][j] = true;
                }
                if(words[i].equals(begin)){
                    this.begin = i;
                }
                if(words[i].equals(target)){
                    this.target = i;
                }
            }
        }
        dfs(this.begin, 0);
        if(ans == Integer.MAX_VALUE) return 0;
        return ans;
    }
    
    private int dist(String s1, String s2){
        int result = 0;
        for(int i =0; i < WN; i++){
            if(s1.charAt(i) != s2.charAt(i)){
                result++;
            }
        }
        return result;
    }
    
    private void dfs(int node, int steps){
        if(steps == N) return;
        if(node == target){
            ans = Math.min(ans, steps);
            return;
        }
        for(int i =0;i < N; i++){
            if(!vs[node][i] && graph[node][i]){
                vs[node][i] = true;
                dfs(i, steps+1);
                vs[node][i] = false;
            }
        }
    }
}