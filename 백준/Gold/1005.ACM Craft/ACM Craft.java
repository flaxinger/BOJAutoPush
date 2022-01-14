import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

    static int T, N, K, W;
    static ArrayList<Integer> arr[];
    static int cost[];
    static int dp[];

    public static int dfs(int node){
        
        if(dp[node] > -1) return dp[node];
        int max = 0;
        for(int i = 0; i<arr[node].size();i++){
            max = Math.max(max, dfs(arr[node].get(i)));
        }
        dp[node] = cost[node]+max;
        return dp[node];
    }
    
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.valueOf(st.nextToken());
        int S, E;
        
        for(int t = 0; t < T; t++){
            st = new StringTokenizer(br.readLine());
            N = Integer.valueOf(st.nextToken());
            K = Integer.valueOf(st.nextToken());
            arr = new ArrayList[N+1];
            cost = new int[N+1];
            dp = new int[N+1];
            st = new StringTokenizer(br.readLine());
            
            for(int n = 1; n < N+1; n++){
                cost[n] = Integer.valueOf(st.nextToken());
                arr[n] = new ArrayList<>();
                dp[n] = -1;
            }
            
            for(int k = 0; k < K; k++){
                st = new StringTokenizer(br.readLine());
                S = Integer.valueOf(st.nextToken());
                E = Integer.valueOf(st.nextToken());
                arr[E].add(S);
            }
            st = new StringTokenizer(br.readLine());
            W = Integer.valueOf(st.nextToken());            
            System.out.println(dfs(W));
        }
            
    }
}