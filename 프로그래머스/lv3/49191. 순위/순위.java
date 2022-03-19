class Solution {
    public static int NONE = 0;
    public static int WIN = 1;
    public static int LOSE = 2;
    public int solution(int N, int[][] results) {
        int answer = 0;
        int[][] board = new int[N+1][N+1];
        int trueCount[] = new int[N+1];
        
        for(int[] r: results){
            board[r[0]][r[1]] = WIN;
            board[r[1]][r[0]] = LOSE;
            trueCount[r[0]]++;
            trueCount[r[1]]++;
        }
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j || board[i][j] != NONE) continue; // board[j][i]는 유추할 수 있어 생략
                for(int k = 1; k <= N; k++){
                    if(i == k || j == k || board[i][k] == NONE) continue;
                    if(board[i][k] == board[k][j]){
                        if(board[i][k] == WIN){
                            board[i][j] = WIN;
                            board[j][i] = LOSE;
                        }
                        else{
                            board[i][j] = LOSE;
                            board[j][i] = WIN;
                        }
                        trueCount[i]++;
                        trueCount[j]++;
                        break;
                    }
                }
            }
        }
        N--;
        for(int t: trueCount){
            if(t==N)
                answer++;
        }
        return answer;
    }
}