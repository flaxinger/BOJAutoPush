import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

    static int N, ans = Integer.MAX_VALUE-1;
    static int[][] dp;
    static int done, buff;
    static ArrayList<Node>[] arr;
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.valueOf(st.nextToken());        
        done = (1<<N)-1;
        arr = new ArrayList[N];
        dp = new int[N][1<<N];

        for(int i =0; i< N; i++)
            Arrays.fill(dp[i], -1);

        for(int i =0; i < N; i++)
            arr[i] = new ArrayList<>();

        for(int i =0;i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j =0; j < N; j++){
                buff = Integer.valueOf(st.nextToken());
                if(buff > 0) 
                    arr[i].add(new Node(j, buff));
            }
        }

        // dfs(0, 0);
        System.out.println(dfs(0, 0));
    }

    static class Node{

        int node, cost;
        Node(int node, int cost){
            this.node = node;
            this.cost = cost;
        }
    }


    static int dfs(int target, int visited){

        if(dp[target][visited] !=-1) return dp[target][visited];
        
        if(target == 0 && visited == done){
            // System.out.println("done");
            return 0;
        }

        int min = Integer.MAX_VALUE-1;
        int tmp =-1, n, c;
        for(int i =0;i < arr[target].size(); i++){
            n = arr[target].get(i).node;
            c = arr[target].get(i).cost;
            if((visited&1<<n) == 0){
                tmp = dfs(n, visited|1<<n);
                if(tmp >-1) min = Math.min(min, tmp+c);
            }
        }
        dp[target][visited]=min;
        if(min == Integer.MAX_VALUE-1){
            dp[target][visited]=-2;
            return -2;
        }
        else return min;
    }
}