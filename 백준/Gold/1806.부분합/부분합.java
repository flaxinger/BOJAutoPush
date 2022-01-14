import java.util.*;
import java.lang.*;
import java.io.*;

class Main{


  
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    int N;
    int end, start;
    int T, sum, ans = Integer.MAX_VALUE;
    int[] arr;
    N = Integer.valueOf(st.nextToken());
    T = Integer.valueOf(st.nextToken());

    arr = new int[N];

    st = new StringTokenizer(br.readLine());
    for(int i = 0;i < N; i++){
      arr[i] = Integer.valueOf(st.nextToken());
    }


    start = 0;
    end = 1;
    sum = arr[0];
    while(true){
      if(start!=end && sum >= T){
        ans = Math.min(ans, end-start);
      }
      if(sum < T || start == end){
        if(end >= N) break;
        sum+=arr[end];
        end++;
      }
      else{
        sum-=arr[start];
        start++;
      }
    }

    System.out.println(ans==Integer.MAX_VALUE?0:ans);

  }
}