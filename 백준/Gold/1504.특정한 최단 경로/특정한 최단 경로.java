/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{
  static int N;
  static int [][] dp;
  static int INF = 10000001;
  public static void main (String[] args) throws java.lang.Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.valueOf(st.nextToken());
    int E = Integer.valueOf(st.nextToken());
    // st = new StringTokenizer(br.readLine());
    dp = new int[N+1][N+1];
    
    int S, T;
    int C;
    
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(i == j) dp[i][j] = 0;
        else dp[i][j] = INF;
      }
    }

    for(int i = 0; i < E; i++){
      st = new StringTokenizer(br.readLine());
      S = Integer.valueOf(st.nextToken());
      T = Integer.valueOf(st.nextToken());
      C = Integer.valueOf(st.nextToken());
      
      if(dp[S][T] > C) 
        dp[S][T] = C;
      if(dp[T][S] > C)
        dp[T][S] = C;
    }
    int vone, vtwo;
    st = new StringTokenizer(br.readLine());

    vone = Integer.valueOf(st.nextToken());
    vtwo = Integer.valueOf(st.nextToken());
    
    for(int k = 1; k <= N; k++){
      for(int i = 1; i <= N; i++){
        if(i == k) continue;
        for(int j = 1; j <= N; j++){
          if(i == j || j == k) continue;
          // System.out.printf("dp[%d][%d] = %d(input is %d)\n", i, j, dp[i][j], dp[i][k]+dp[k][j]);
          dp[i][j] = Math.min(dp[i][j], (dp[i][k] + dp[k][j]));
          // System.out.printf("\tafter update: dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
      }
    }
    int ans = Math.min(dp[1][vone]+dp[vone][vtwo]+dp[vtwo][N], dp[1][vtwo] + dp[vtwo][vone] + dp[vone][N]);
    if(ans >= INF) ans = -1;
    System.out.println(ans);
  }
}