/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main
{

  static Integer[] dp;
  static int[] nums;
  static int N;

  public static int solve(int idx){

    if(dp[idx]!=null) return dp[idx];
    dp[idx] = 1;

    for(int i = idx-1; i >= 0; i--){
      if(nums[idx] > nums[i]){
        dp[idx] = Math.max(dp[idx], solve(i)+1);
      }
    }
    return dp[idx];
  }

  public static void main (String[] args) throws java.lang.Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    nums = new int[N];
    dp = new Integer[N];

    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < N; i++){
      nums[i] = Integer.valueOf(st.nextToken());  
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = Math.max(ans, solve(i));
    }
    System.out.println(ans);
  }
}