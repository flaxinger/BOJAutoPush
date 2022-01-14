import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String s1, s2;
    int[][] board;
    String[][] result;

    int N, M;
    StringTokenizer st = new StringTokenizer(br.readLine());
    s1 = String.valueOf(st.nextToken());
    st = new StringTokenizer(br.readLine());
    s2 = String.valueOf(st.nextToken());
    N = s1.length();
    M = s2.length();
    board = new int[N][M];
    result = new String[N][M];

    for(String[] a: result)
      Arrays.fill(a, "");

    for(int i =0;i < N; i++){
      if(s1.charAt(i) == s2.charAt(0)){
        board[i][0] = 1;
        result[i][0] += s1.charAt(i);
      }
      else if(i > 0){
        board[i][0] = board[i-1][0];
        result[i][0] = result[i-1][0];
      }
    }
    for(int i =0;i < M; i++){
      if(s2.charAt(i) == s1.charAt(0)){
        board[0][i] = 1;
        result[0][i] += s1.charAt(0);
      }
      else if(i > 0){
        board[0][i] = board[0][i-1];
        result[0][i] = result[0][i-1];
      }
    }
    for(int i = 1;i < N; i++){
      for(int j =1; j < M; j++){
        if(s1.charAt(i) == s2.charAt(j)){
          board[i][j] = board[i-1][j-1]+1;
          result[i][j] = result[i-1][j-1] + s1.charAt(i);
        }
        else{
          board[i][j] = board[i-1][j-1];
          result[i][j] = result[i-1][j-1];
        }
        if(board[i][j] <board[i][j-1]){
          board[i][j] = board[i][j-1];
          result[i][j] = result[i][j-1];
        }
        if(board[i][j] < board[i-1][j]){
          board[i][j] = board[i-1][j];
          result[i][j] = result[i-1][j];
        }
      }
    }

    System.out.println(board[N-1][M-1]);
    System.out.println(result[N-1][M-1]);
  }
}