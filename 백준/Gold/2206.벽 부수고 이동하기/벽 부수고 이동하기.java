/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */


class Main
{

  static int board[][][];
  static int dx[] = {-1, 1, 0, 0};
  static int dy[] = {0, 0, -1, 1};
  static boolean[][][] vs;
  static int N, M;
  static boolean reached;

  public static class Node implements Comparable<Node>{
    
    int x, y, z, cost;

    public Node(int x, int y, int z, int cost){
      this.x = x;
      this.y = y;
      this.z = z;
      this.cost = cost;
    }

    // @Override
    public int compareTo(Node a){
      return this.cost < a.cost ? 1 : -1;
    }

  }

  static Queue<Node> pq;

  public static void solve(Node node){

    int nx, ny;

    for(int i = 0 ; i < 4; i++){
      nx = node.x+dx[i];
      ny = node.y+dy[i];
      if(nx >= 0 && nx < N && ny >= 0 && ny < M){
        if(board[nx][ny][0] == 1 && node.z == 0 && vs[nx][ny][1] == false){
            pq.add(new Node(nx, ny, node.z+1, node.cost+1));
            vs[nx][ny][1] = true;
        }
        else if(board[nx][ny][0] == 0 && vs[nx][ny][node.z] == false){
            pq.add(new Node(nx, ny, node.z, node.cost+1));
            vs[nx][ny][node.z] = true;
        }
      }
    }
  }

  public static void main (String[] args) throws java.lang.Exception
  {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    pq = new LinkedList<Node>();
    board = new int[N][M][2];
    vs = new boolean[N][M][2];
    
    // for(boolean[] arr: vs)
        // Arrays.fill(arr, false);

    String buff;
    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      buff = String.valueOf(st.nextToken());
      for(int j = 0; j < M; j++){
        board[i][j][0] = Integer.valueOf(buff.charAt(j)-'0');
        board[i][j][1] = board[i][j][0];
      }
    }

    pq.add(new Node(0,0,0,1));
    while(pq.size()>0 && !(pq.peek().x == N-1 && pq.peek().y == M-1)){
      // System.out.printf("(%d, %d, %d) = %d\n", pq.peek().x, pq.peek().y, pq.peek().z, pq.peek().cost);
      solve(pq.poll());
    }

    if(pq.size() == 0)
      System.out.println(-1);
    else
      System.out.println(pq.peek().cost);
  }
}