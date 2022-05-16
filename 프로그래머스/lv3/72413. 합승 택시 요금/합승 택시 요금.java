import java.util.*;

class Solution {
    
    
    public int solution(int N, int S, int A, int B, int[][] fares) {
        N++;
        int[][] FF = new int[N][N];
        for(int[] F: FF){
            Arrays.fill(F, Integer.MAX_VALUE>>3);
        }
        for(int[] fare: fares){
            int X = fare[0];
            int Y = fare[1];
            int price = fare[2];
            FF[X][Y] = price;
            FF[Y][X] = price;
        }
        
        for(int i = 1; i < N; i++){
            FF[i][i]=0;
        }
        for(int k = 1; k < N; k++){
            for(int i =1;i < N; i++){
                for(int j =1; j < N; j++){
                    if(i!=j){
                        FF[i][j] = Math.min(FF[i][j], FF[i][k]+FF[k][j]);
                    }
                }
            }
        }
    
        int answer = Integer.MAX_VALUE;
        for(int i = 1; i< N; i++){
            answer = Math.min(answer, FF[S][i]+FF[i][A]+FF[i][B]);
        }
        return answer;
    }
}