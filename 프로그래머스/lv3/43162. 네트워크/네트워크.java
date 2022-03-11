class Solution {
    
    private int ans, N;
    private int[][] node;
    private boolean[][] vs;
    public int solution(int n, int[][] node) {
        this.ans = 0;
        this.N = n;
        this.node = node;
        this.vs = new boolean[N][N];
        
        for(int i =0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(node[i][j]==1 && !vs[i][j]){
                    ans++;
                    dfs(i);
                    // dfs(j);
                }
            }    
        }
        return ans;
    }
    
    private void dfs(int idx){
        
        for(int i = 0; i < N; i++){
            // if(i == idx) continue;
            if(node[idx][i] == 1 && !vs[idx][i]){
                vs[idx][i] = true;
                dfs(i);
            }
        }
    }
}