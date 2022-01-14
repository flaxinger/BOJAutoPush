import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

    static int sum, N;
    static int[] dp;
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		String string = String.valueOf(st.nextToken());		
		N = string.length();
		dp = new int[N+1];
		for(int i = 0;i <= N; i++){
			dp[i] = i;
		}
		int left = 0, right = 0;
		for(int i =0; i < N; i++){
			
			// i-1 == string.idx
			left = i-1;
			right = i+1;
			
			while(left>= 0 && right < N && string.charAt(left) == string.charAt(right)){
				dp[right+1] = Math.min(dp[left]+1, dp[right+1]);
				left--;
				right++;
			}

			left+=2;
			
			dp[i+1] = Math.min(dp[i+1], dp[i]+1);
			// dp[right] = Math.min(dp[left-1]+1, dp[right]);

			if(i < N-1){
				left = i;
				right = i+1;
				
				while(left>= 0 && right < N && string.charAt(left) == string.charAt(right)){
					dp[right+1] = Math.min(dp[left]+1, dp[right+1]);
					left--;
					right++;
				}

				left+=2;
				// dp[right] = Math.min(dp[left-1]+1, dp[right]);
				
			}
		}
		// for(int x: dp) System.out.printf("%d ", x);
		// System.out.println();
        System.out.println(dp[N]);

    }
}