import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static int[][] board, dp;
  static int N, M;

  public static int func(int a, int b, int c, int d){

    int one = 0, two = 0, three = 0;
    if(a>0) one = dp[a-1][d];
    if(b>0) two = dp[c][b-1];
    if(a>0 && b>0) three = dp[a-1][b-1];
    return dp[c][d] + three - one - two; 
  }
  public static void solve() throws java.lang.Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    board = new int[N][N];
    dp = new int[N][N];
    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j = 0; j < N; j++){
        board[i][j] = Integer.valueOf(st.nextToken());
      }
    }

    int e, f, g;
    for(int i = 0; i< N; i++){
      for(int j = 0; j < N; j++){
        e = 0; f = 0; g= 0;
        if(i > 0) e = dp[i-1][j];
        if(j > 0) f = dp[i][j-1];
        if(i > 0 && j > 0) g = dp[i-1][j-1];
        dp[i][j] = e+f+board[i][j]-g;
      }
    }

    // for(int i = 0; i < N; i++) System.out.println(Arrays.toString(dp[i]));

    for(int i = 0; i < M; i++){
      st = new StringTokenizer(br.readLine());
      int a = Integer.valueOf(st.nextToken());
      int b = Integer.valueOf(st.nextToken());
      int c = Integer.valueOf(st.nextToken());
      int d = Integer.valueOf(st.nextToken());
      System.out.println(func(a-1, b-1, c-1, d-1));
    }
  }

  public static void main(String[] args) throws java.lang.Exception{
    solve();
  } 
}