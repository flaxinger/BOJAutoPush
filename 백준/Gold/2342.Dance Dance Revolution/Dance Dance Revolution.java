import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

	static int ans, a, b;
	static int[][][] dp;
	static final int INF = Integer.MAX_VALUE>>1;
	static int[] x = {0, 0, 0, 0, 1, 1, 1, 2, 2, 3};
	static int[] y = {1, 2, 3, 4, 2, 3, 4, 3, 4, 4};

	static int[][] cost = {
		{INF, 2, 2, 2, 2},
		{INF, 1, 3, 4, 3},
		{INF, 3, 1, 3, 4},
		{INF, 4, 3, 1, 3},
		{INF, 3, 4, 3, 1}
	};

	
	static ArrayList<Integer> arr;
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		arr = new ArrayList<>();
		int buff = Integer.valueOf(st.nextToken());
		while(buff!=0){
			arr.add(buff);
			buff = Integer.valueOf(st.nextToken());
		}
		
		dp = new int[5][5][arr.size()];
		for(int[][] a: dp)
			for(int[] b: a)
				Arrays.fill(b, INF);
		
		dp[0][arr.get(0)][0] = 2;
		int cx, cy, next, cur;
		for(int j = 1; j < arr.size(); j++){
			next = arr.get(j);
			for(int i = 0;i < 10; i++){
				cx = x[i];
				cy = y[i];
				cur = dp[cx][cy][j-1];
				if(cur < INF){
					if(cy!=next){
						if(next < cy){
							dp[next][cy][j] = Math.min(dp[next][cy][j], cur + cost[cx][next]);
						}
						else{
							dp[cy][next][j] = Math.min(dp[cy][next][j], cur + cost[cx][next]);
						}
					}		
					if(cx!=next){
						if(next < cx){
							dp[next][cx][j] = Math.min(dp[next][cx][j], cur + cost[cy][next]);
						}
						else{
							dp[cx][next][j] = Math.min(dp[cx][next][j], cur + cost[cy][next]);
						}
					}
				}
			}
		}

		int ans = INF;
		for(int i = 0; i < 10; i++){
			ans = Math.min(ans, dp[x[i]][y[i]][arr.size()-1]);
		}
		System.out.println(ans);
    }
}