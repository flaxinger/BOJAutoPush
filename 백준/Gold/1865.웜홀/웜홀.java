/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main
{
  static int tc, N, M, W;
  static ArrayList<Integer>[] m;
  static ArrayList<Integer>[] c;
  public static void main (String[] args) throws java.lang.Exception
  {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    m = new ArrayList[501];
    c = new ArrayList[501];
    
    int S, E, T;

    int[] dist;
    tc = Integer.valueOf(st.nextToken());

    for(int i = 0; i < tc; i++){
      st = new StringTokenizer(br.readLine());
      N = Integer.valueOf(st.nextToken());
      M = Integer.valueOf(st.nextToken());
      W = Integer.valueOf(st.nextToken());

      for(int j = 0; j <= N; j++){
        m[j] = new ArrayList<Integer>();
        c[j] = new ArrayList<Integer>();
      }

      dist = new int[N+1];
      for(int j = 0; j < M; j++){
        st = new StringTokenizer(br.readLine());
        S = Integer.valueOf(st.nextToken());
        E = Integer.valueOf(st.nextToken());
        T = Integer.valueOf(st.nextToken());
        
        m[S].add(E);
        c[S].add(T);
        m[E].add(S);
        c[E].add(T);

      }
      for(int j = 0; j < W; j++){
        st = new StringTokenizer(br.readLine());
        S = Integer.valueOf(st.nextToken());
        E = Integer.valueOf(st.nextToken());
        T = Integer.valueOf(st.nextToken());
  
        m[S].add(E);
        c[S].add(-T);
      }
      
      
      Arrays.fill(dist, 27000001);
      dist[1] = 0;
      int p = 0, j;
      int sum = 0;
      boolean update;
      while(p++ <= N){
        j = 0;
        update = false;
        while(j++ < N){
          // System.out.println(j);
          for(int k = 0; k < m[j].size(); k++){
            if(dist[m[j].get(k)]>dist[j]+c[j].get(k)){
              dist[m[j].get(k)] = dist[j]+c[j].get(k);
              update= true;
            }
          }
        }
        if(update) sum++;
        else break;
      }

      
      // if(dist[1]<0) sum = N+1;
      if(sum > N){
        System.out.println("YES");
      }
      else{
        System.out.println("NO");
      }
      
    }
  }
}