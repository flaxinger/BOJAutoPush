import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int T, N;
    int[] arr;
    int[] vs;
    StringBuilder sb = new StringBuilder("");
    StringTokenizer st = new StringTokenizer(br.readLine());
    T = Integer.valueOf(st.nextToken());
    
    while(T-->0){
      st = new StringTokenizer(br.readLine());
      N = Integer.valueOf(st.nextToken());

      arr = new int[N+1];
      vs = new int[N+1];

      st = new StringTokenizer(br.readLine());
      for(int i = 1;i <= N; i++){
        arr[i] = Integer.valueOf(st.nextToken());
      }

      int id = 1, cur = 0, start = id, ans = 0;
      for(int i = 1;i <= N; i++){
        if(vs[i] == 0){
          cur = i;
          start = id;
          while(vs[cur] == 0){
            vs[cur] = id;
            cur = arr[cur];
            id++;
          }

          if(vs[cur] >= start && cur == arr[cur]){
            ans++;
          }
          else if(vs[cur] >= start){
            ans+=id-vs[cur];
          }
        }
      }
      sb.append(N-ans+"\n");
    }

    System.out.println(sb);
  }
}