import java.util.*;
import java.math.*;
import java.lang.*;

class Solution {
    
        
    public int solution(
        int N,              // 거점 개수
        int M,              // 도로 개수
        int[][] edgeList,   // 간선 정보
        int K,              // GPS 정보 총 개수
        int[] gps           // GPS 정보 배열
    ) {
        N++;
        ArrayList<Integer>[] road = new ArrayList[N];
        int[][] dp = new int[K][N];
        for(int i = 0; i< N; i++){
            road[i] = new ArrayList<>();
        }
        for(int[] edge: edgeList){
            road[edge[0]].add(edge[1]);
            road[edge[1]].add(edge[0]);
        }
        for(int i = 1;i < N; i++){
            road[i].add(i);
        }
        for(int[] dpp: dp){
            Arrays.fill(dpp, Integer.MAX_VALUE>>1);
        }
        
        dp[0][gps[0]] = 0;
        for(int i = 1;i < K; i++){
            for(int j = 1; j < N; j++){
                for(int prev: road[j]){
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][prev]+((j==gps[i])?0:1));
                }
            }
        }
        
        if(dp[K-1][gps[K-1]] == Integer.MAX_VALUE>>1) return -1;
        return dp[K-1][gps[K-1]];
    }
    
}