/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{

  static int N, M, X;
  static int[][] arr;
  static final int INF = Integer.MAX_VALUE>>1;
  public static void main (String[] args) throws java.lang.Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    X = Integer.valueOf(st.nextToken());
    arr = new int[N+1][N+1];
    int S, E, T;

    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(i == j) arr[i][j] = 0;
        else arr[i][j] = INF;
      }
    }

    for(int i = 0; i < M; i++){
      st = new StringTokenizer(br.readLine());

      S = Integer.valueOf(st.nextToken());
      E = Integer.valueOf(st.nextToken());
      T = Integer.valueOf(st.nextToken());

      if(arr[S][E] > T) arr[S][E] = T;
    }

    for(int k = 1; k <= N; k++)
      for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
          arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);

    // for(int i = 1; i <= N; i++){
    //   for(int j = 1; j <= N; j++){
    //     System.out.printf("%d ", arr[i][j]);
    //   }
    //   System.out.println();
    // }
    int ans = 0;

    for(int i = 1; i <= N; i++)
      ans = Math.max(ans, arr[i][X] + arr[X][i]);

    System.out.println(ans);
  
  }
}