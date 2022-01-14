/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{

  static int N, M, X;
  static int[][] arr;
  static int[][] dp;
  static int[][] dpmin;


  static final int INF = Integer.MAX_VALUE>>1;
  public static void main (String[] args) throws java.lang.Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
 
    arr = new int[N][3];
    dp = new int[N][3];
    dpmin = new int[N][3];

    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());

      arr[i][0] = Integer.valueOf(st.nextToken());
      arr[i][1] = Integer.valueOf(st.nextToken());
      arr[i][2] = Integer.valueOf(st.nextToken());
    }


    for(int i = 0; i < N; i++)
      for(int j = 0; j < 3; j++)
        dpmin[i][j] = INF;

    dp[N-1][0] = arr[N-1][0];
    dp[N-1][1] = arr[N-1][1];
    dp[N-1][2] = arr[N-1][2];
    dpmin[N-1][0] = arr[N-1][0];
    dpmin[N-1][1] = arr[N-1][1];
    dpmin[N-1][2] = arr[N-1][2];


    for(int i = N-2; i >= 0; i--){
      // if(i < 0) break;
      for(int j = 0; j < 3; j++){

        if(j-1 >= 0){
          dp[i][j] = Math.max(dp[i][j], dp[i+1][j-1] + arr[i][j]);
          dpmin[i][j] = Math.min(dpmin[i][j], dpmin[i+1][j-1] + arr[i][j]);
        }
        dp[i][j] = Math.max(dp[i][j], dp[i+1][j] + arr[i][j]);
        dpmin[i][j] = Math.min(dpmin[i][j], dpmin[i+1][j] + arr[i][j]);
        if(j+1 < 3){
          dp[i][j] = Math.max(dp[i][j], dp[i+1][j+1] + arr[i][j]);
          dpmin[i][j] = Math.min(dpmin[i][j], dpmin[i+1][j+1] + arr[i][j]);
        }
      }
    }


    System.out.printf("%d ", Math.max(dp[0][0], Math.max(dp[0][1], dp[0][2])));
    System.out.println(Math.min(dpmin[0][0], Math.min(dpmin[0][1], dpmin[0][2])));

  }
}