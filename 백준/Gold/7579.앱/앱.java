import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static int N, M, C = 0;
  static int[] dp, mem, cost;

  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    mem = new int[N];
    cost = new int[N];

    st = new StringTokenizer(br.readLine());
    for(int i =0;i < N; i++){
      mem[i] = Integer.valueOf(st.nextToken());
    }

    st = new StringTokenizer(br.readLine());
    for(int i =0;i < N; i++){
      cost[i] = Integer.valueOf(st.nextToken());
      C+=cost[i];
    }

    dp = new int[C+1];
    for(int i =0;i < N; i++){
      for(int j = C; j >= cost[i]; j--){
        dp[j] = Math.max(dp[j], dp[j-cost[i]]+mem[i]);
      }
    }

    int i = 0;
    for(; i < C && dp[i] < M; i++);
    System.out.println(i);
  
  }
}