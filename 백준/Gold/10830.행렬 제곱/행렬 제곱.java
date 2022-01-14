/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{

  static int N;
  static Long P;
  static int[][] iden;
  static int[][] Matrix;
  static int DIV = 1000;
  static Map<Long, int[][]> map;

  static final int INF = Integer.MAX_VALUE>>1;
  public static void main (String[] args) throws java.lang.Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    P = Long.valueOf(st.nextToken());
    map = new HashMap<Long, int[][]>();
    Matrix = new int[N][N];
    iden = new int[N][N];

    for(int i = 0; i< N; i++){
      st = new StringTokenizer(br.readLine());

      for(int j =0; j < N; j++){
        Matrix[i][j] = Integer.valueOf(st.nextToken())%DIV;
      }
    }

    for(int i= 0; i< N; i++){
      for(int j =0; j < N; j++){
        if(i==j) iden[i][j] = 1;
        else iden[i][j] = 0;
      }
    }

    int[][] ans = pow(P);

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        System.out.printf("%d ", ans[i][j]);
      }
      System.out.println();
    }
  }

  public static int[][] pow(Long pow){

    if(pow == 0) return iden;
    if(pow == 1) return Matrix;
    if(map.containsKey(pow)) return map.get(pow);
    int ans[][] = new int[N][N];

    Long half1 = pow/2;
    Long half2 = pow - half1;

    int[][] arr1 = pow(half1);
    int[][] arr2 = pow(half2);

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        ans[i][j] = 0;

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        for(int k = 0; k < N; k++){
          ans[i][j] = (ans[i][j] + arr1[i][k] * arr2[k][j]) % DIV;
        }
      }
    }
    map.put(pow, ans);
    return ans;
  }

}