import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String s1, s2;
    int[] arr;
    boolean[][] board;

    int N;
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.valueOf(st.nextToken());
    
    arr = new int[N];
    board = new boolean[N][N];

    st = new StringTokenizer(br.readLine());
    for(int i =0;i < N; i++){
      arr[i] = Integer.valueOf(st.nextToken());
    }

    int s = 0, e = 0;
    boolean c1, c2;
    for(int i = 0;i < N; i++){
      c1 = true;
      c2 = true;
      s = i; e = i;
      while(s >= 0 && e < N-1 && (c1 || c2)){
        if(c1 && arr[s] == arr[e]){
          board[s][e] = true;
        }
        else c1 = false;
        if(c2 && arr[s] == arr[e+1]){
          board[s][e+1] = true;
        }
        else c2 = false;
        s--;e++;
      }
      if(s>=0 && e < N
       && c1 && arr[s] == arr[e]) board[s][e] = true;
    }


    st = new StringTokenizer(br.readLine());
    N = Integer.valueOf(st.nextToken());

    StringBuilder sb = new StringBuilder();
    for(int i =0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      s = Integer.valueOf(st.nextToken());
      e = Integer.valueOf(st.nextToken());
      sb.append(board[s-1][e-1]?"1\n":"0\n");
    }
    System.out.println(sb);
  }
}