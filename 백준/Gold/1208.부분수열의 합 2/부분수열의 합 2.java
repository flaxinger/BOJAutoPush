import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

    static int N, S;
    static Long result = 0L;
    static int[] arr;
    static Map<Integer, Integer> dp;
    
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
        dp = new HashMap<>();
		N = Integer.valueOf(st.nextToken());		
        S = Integer.valueOf(st.nextToken());

        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i < N; i++){
            arr[i] = Integer.valueOf(st.nextToken());
        }

        set(0, N/2);
        calc(N/2, N);

        System.out.println(result);
    }

    public static void set(int start, int end){
        int num;
        for(int i = 1; i < 1<<(end-start); i++){
            num = 0;
            for(int j = 0; j < end-start; j++){
                if((i & (1 << j)) > 0){
                    num+=arr[start+j];
                }
            }
            if(num == S) result++;
            dp.putIfAbsent(num, 0);
            dp.replace(num, dp.get(num)+1);
        }
    }
    public static void calc(int start, int end){
        int num;
        for(int i = 1; i < 1<<(end-start); i++){
            num = 0;
            for(int j = 0; j < end-start; j++){
                if((i & (1 << j)) > 0){
                    num+=arr[start+j];
                }
            }
            if(num == S) result++;
            if(dp.containsKey(S-num)) result+=dp.get(S-num);
        }
    }
}