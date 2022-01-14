import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static int N, M;
  static ArrayList<Integer>[] arr;
  static int[] deg;
  
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    PriorityQueue<Integer> q = new PriorityQueue<>();
    arr = new ArrayList[N+1];
    deg = new int[N+1];

    for(int i = 1; i <= N; i++){
      arr[i] = new ArrayList<>();
    }

    int first, second;
    while(M-- > 0){
      st = new StringTokenizer(br.readLine());
      first = Integer.valueOf(st.nextToken());
      second = Integer.valueOf(st.nextToken());
      arr[first].add(second);
      deg[second]++;
    }


    for(int i = 1; i<= N; i++){
      if(deg[i] == 0)
        q.add(i);
    }

    int cur;
    StringBuffer sb = new StringBuffer();
    while(q.size()>0){
      cur = q.poll();
      sb.append(cur+" ");
      for(int num: arr[cur]){
        deg[num]--;
        if(deg[num]==0)
          q.add(num);
      }
    }

    System.out.println(sb.toString());
  }
}