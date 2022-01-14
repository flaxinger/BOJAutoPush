import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static Map<Integer, ArrayList<Integer>> map;
  static int[] ans, vs;
  static int N;

  public static void trav(int node, int parent){

    vs[node] = 1;
    if(parent!=0 && ans[node] == 0){
      ans[node] = parent;
    }
    ArrayList<Integer> cur = map.get(node);
    for(int i = 0; i < cur.size(); i++){
      if(vs[cur.get(i)] == 0) trav(cur.get(i), node);
    }
  }
  public static void solve() throws java.lang.Exception {


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.valueOf(br.readLine());
    map = new HashMap<Integer, ArrayList<Integer>>();
    ans = new int[N+1];
    vs = new int[N+1];
    for(int i = 0; i < N-1; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());
      int a = Integer.valueOf(st.nextToken());
      int b = Integer.valueOf(st.nextToken());

      map.putIfAbsent(a, new ArrayList<Integer>());
      map.putIfAbsent(b, new ArrayList<Integer>());

      map.get(a).add(b);
      map.get(b).add(a);
    }
    trav(1, 0);
    for(int i = 2; i <= N; i++) System.out.println(ans[i]);
  }

  public static void main(String[] args) throws java.lang.Exception{
    solve();
  } 
}