/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{
  static Long DIV = 1000000007L;
  static Map<Long, Long[][]> map;
  public static void main (String[] args) throws java.lang.Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    long N;
    map = new HashMap<Long, Long[][]>();
    N = Long.valueOf(st.nextToken());
    Long [][] mat = {{1L, 1L}, {1L, 0L}};
    Long [][] base = {{1L}, {0L}};

    // Long [][] chk = pow(mat, N);
    // System.out.printf("{{%d, %d},\n{%d, %d}}\n", chk[0][0], chk[0][1], chk[1][0], chk[1][1]);

    Long ans[][] = mult(pow(mat, N-1), base);

    if(N == 0) System.out.println(0);
    else System.out.println(ans[0][0]);
  
  }


  public static Long[][] pow(Long[][] a, Long p){

    Long[][] iden = {{1L, 0L}, {0L, 1L}};
    if(map.containsKey(p)) return map.get(p);
    if(p == 1) return a;
    if(p == 0) return iden;

    Long half1 = p/2;
    Long half2 = half1 - p;

    Long a1[][] = pow(a, half1);
    Long a2[][] = pow(a, half2);

    Long ans[][] = {{0L, 0L}, {0L, 0L}};

    ans[0][0] = (a1[0][0] * a2[0][0] + a1[0][1] * a2[1][0])%DIV;
    ans[0][1] = (a1[0][0] * a2[0][1] + a1[0][1] * a2[1][1])%DIV;
    ans[1][0] = (a1[1][0] * a2[0][0] + a1[1][1] * a2[1][0])%DIV;
    ans[1][1] = (a1[1][0] * a2[0][1] + a1[1][1] * a2[1][1])%DIV;

    map.put(p, ans);
    return ans;
  }


  public static Long[][] mult(Long[][] a, Long[][] b){
    Long[][] result = {{0L}, {0L}};

    result[0][0] = (a[0][0] * b[0][0])%DIV + (a[0][1] * b[1][0])%DIV;
    result[1][0] = (a[1][0] * b[0][0])%DIV + (a[1][1] * b[1][0])%DIV;

    return result;
  }

}