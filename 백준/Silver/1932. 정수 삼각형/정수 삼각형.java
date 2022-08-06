/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main
{

  static int[][] nums;
  static int N;

  public static void main (String[] args) throws java.lang.Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    nums = new int[N][N];

    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j = 0; j <= i; j++){
        nums[i][j] = Integer.valueOf(st.nextToken());  
      }
    }

    for(int i = N-2; i >= 0; i--){
      for(int j = 0; j <= i; j++){
        nums[i][j] += Math.max(nums[i+1][j], nums[i+1][j+1]);
      }
    }

    System.out.println(nums[0][0]);

  }
}