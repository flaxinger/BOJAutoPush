import java.util.*;
import java.lang.*;
import java.io.*;


class Main{
  
  static int N, best = 0, bestnode;
  static Integer vs[];
  static Map<Integer, ArrayList<Integer[]>> E;
  public static void solve() throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    E = new HashMap<Integer, ArrayList<Integer[]>>();
    N = Integer.valueOf(st.nextToken());
    if(N==1){
      System.out.println(0);
      return;
    }
    vs = new Integer[N+1];
    Integer vOne = 0, vTwo = 0, cost = 0;
    ArrayList<Integer[]> tmpOne;
    ArrayList<Integer[]> tmpTwo;
    Integer one[];
    Integer two[];

    for(int i =0; i < N-1; i++){
      st = new StringTokenizer(br.readLine(), " ");
      vOne = Integer.valueOf(st.nextToken());
      vTwo = Integer.valueOf(st.nextToken());
      cost = Integer.valueOf(st.nextToken());
      
      tmpOne = new ArrayList<Integer[]>();
      tmpTwo = new ArrayList<Integer[]>();
      if(E.containsKey(vOne))  tmpOne = E.get(vOne);
      if(E.containsKey(vTwo))  tmpTwo = E.get(vTwo);

      one = new Integer[2];
      two = new Integer[2];
      one[0] = vTwo;
      one[1] = cost;
      two[0] = vOne;
      two[1] = cost;

      tmpOne.add(one);
      tmpTwo.add(two);
      E.put(vOne, tmpOne);
      E.put(vTwo, tmpTwo);
    }


    Arrays.fill(vs, 0);
    trav(1, 0);
    Arrays.fill(vs, 0);
    trav(bestnode, 0);
    System.out.println(best);
  }

  public static void trav(int node, int sum){

    vs[node] = 1;
    if(sum > best){
      best = sum;
      bestnode = node;
    }
    ArrayList<Integer[]> n = E.get(node);
    for(int i = 0; i < n.size(); i++){
      if(vs[n.get(i)[0]] != 1) trav(n.get(i)[0], sum + n.get(i)[1]);
    }
  }

  public static void main(String[] args) throws java.lang.Exception{
    solve();
  } 
}