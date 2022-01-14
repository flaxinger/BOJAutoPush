import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static int N, ans = 0;
  static ArrayList<Integer> arr;
  static int[][] dp;
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    
    N = Integer.valueOf(st.nextToken());
    arr = new ArrayList<>();
    dp = new int[N][N];
    int a, b;
    for(int i =0;i < N; i++){
      st = new StringTokenizer(br.readLine());
      a = Integer.valueOf(st.nextToken());
      b = Integer.valueOf(st.nextToken());
      if(i == 0)
        arr.add(a);
      arr.add(b);
    }

    int z;
    for(int i =1;i < N; i++){
      for(int j = 0; j < N-i; j++){
        z = i+j;
        dp[j][z] = Integer.MAX_VALUE;
        for(int k = j; k < z; k++){
          dp[j][z] = Math.min(dp[j][z], dp[j][k]+dp[k+1][z]+((j-1 >= 0)?arr.get(j-1):arr.get(arr.size()-1))*arr.get(k)*arr.get(z));
        }
      }
    }
        
    System.out.println(dp[0][N-1]);
  }
}