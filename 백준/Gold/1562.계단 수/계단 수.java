import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

    static int N;
    static long MOD = 1000000000L;    
    static long[][][] dp;
    static int done = (1<<10)-1;
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.valueOf(st.nextToken());		

        dp = new long[N+1][10][1<<10];

        for(int i =0; i<= N; i++) 
            for(int j = 0; j< 10; j++)
                Arrays.fill(dp[i][j], 0L);
        
        for(int i = 1; i < 10; i++){
            dp[1][i][1<<i] = 1L;
        }

        for(int i = 2; i <= N; i++){
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 1<<10; k++){
                    if(j == 0){
                        dp[i][j][k|1<<j] = (dp[i][j][k|1<<j] + dp[i-1][j+1][k])% MOD;
                    }
                    else if(j==9){
                        dp[i][j][k|1<<j] = (dp[i][j][k|1<<j] + dp[i-1][j-1][k])% MOD;   
                    }
                    else{
                        dp[i][j][k|1<<j] = (dp[i-1][j-1][k] +dp[i][j][k|1<<j] + dp[i-1][j+1][k])% MOD;      
                    }
                }
            }
        }

        long sum = 0L;
        for(int i = 0;i < 10; i++){
            sum = (sum+dp[N][i][done])%MOD;
        }
        System.out.println(sum);

    }
}