/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main{

  static int N, R;
  static int[][] iden;
  static int[][] Matrix;
  static ArrayList<Integer>[] C, M;
  static boolean[] vs;

  static class City implements Comparable<City>{
    int cost, city;
    ArrayList<Integer> history;

    public City(int city, int cost){
      this.cost = cost;
      this.city = city;
      this.history = new ArrayList<Integer>();
    }

    @Override
    public int compareTo(City c){
      return this.cost - c.cost;
    }
  }

  static PriorityQueue<City> pq;

  static void solve(City idx){

    vs[idx.city] = true;
    City tmp;
    for(int i = 0; i < C[idx.city].size(); i++){
      if(!vs[M[idx.city].get(i)]){
        tmp = new City(M[idx.city].get(i), C[idx.city].get(i)+idx.cost);
        tmp.history = new ArrayList(idx.history);
        tmp.history.add(idx.city);
        pq.add(tmp);
      }
    }
  }

  public static void main (String[] args) throws java.lang.Exception{
    
    // initialization
    int S, E, T;

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.valueOf(st.nextToken());
    st = new StringTokenizer(br.readLine());
    R = Integer.valueOf(st.nextToken());
    M = new ArrayList[N+1];
    C = new ArrayList[N+1];
    pq = new PriorityQueue<City>();
    vs = new boolean[N+1];
    for(int i =0; i <= N; i++){
      M[i] = new ArrayList<Integer>();
      C[i] = new ArrayList<Integer>();
    }

    for(int i = 0; i < R; i++){
      st = new StringTokenizer(br.readLine());

      S = Integer.valueOf(st.nextToken());
      E = Integer.valueOf(st.nextToken());
      T = Integer.valueOf(st.nextToken());

      M[S].add(E);
      C[S].add(T);
    }

    st = new StringTokenizer(br.readLine());
    S = Integer.valueOf(st.nextToken());
    E = Integer.valueOf(st.nextToken());

    pq.add(new City(S, 0));
    while(pq.size() > 0 && pq.peek().city != E){
      solve(pq.poll());
    }

    System.out.println(pq.peek().cost);
    System.out.println(pq.peek().history.size()+1);
    for(int i =0; i < pq.peek().history.size(); i++){
      System.out.printf("%d ", pq.peek().history.get(i));
    }

    System.out.printf("%d ", pq.peek().city);

  }
}