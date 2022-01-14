import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static class Node implements  Cloneable{
    public int x, y;
    Node(int x, int y){
      this.x = x;
      this.y = y;
    }
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
  }
  static int[] dx = {1, 0, -1, 0};
  static int[] dy = {0, 1, 0, -1};
  static final char W = '#', H = 'O', R = 'R', B = 'B', S = '.';
  static final int MAX = Integer.MAX_VALUE;
  static int N, M, ans = MAX, LIM;
  static char[][] board;
  
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    
    N = Integer.valueOf(st.nextToken());
    M = Integer.valueOf(st.nextToken());
    Node red = new Node(0, 0), blue = new Node(0,0);
    LIM = 10;
    String buff;
    board = new char[N][M];
    for(int i=0;i < N; i++){
      st = new StringTokenizer(br.readLine());
      buff = String.valueOf (st.nextToken());
      for(int j = 0; j < M; j++){
        board[i][j] = buff.charAt(j);
        if(board[i][j] == R){
          red = new Node(i, j);
        }
        else if(board[i][j] == B){
          blue = new Node(i, j);
        }
      }
    }

    solve(red, blue, false, 1);
    solve(red, blue, true, 1);    
    System.out.println(ans==MAX?-1:ans);
  }

  public static void solve(Node red, Node blue, boolean row, int count) throws CloneNotSupportedException {

    if(count > Math.min(ans, LIM)) return;
    // initialize values
    Node nr = new Node(0,0);
    Node nb = new Node(0,0);

    // check all directions
    for(int i = 0; i<4; i++){
      if(row && i%2 == 0) continue;
      if(!row && i%2 != 0) continue;
      if(board[red.x + dx[i]][red.y + dy[i]]!=W || board[blue.x+dx[i]][blue.y+dy[i]] != W){
        nr = (Node)red.clone();
        nb = (Node)blue.clone();
        // move red, blue, red
        nr = move(nr, i, true);
        nb = move(nb, i, false);
        nr = move(nr, i, true);

        if(board[nb.x][nb.y]==H){
          clean(nr, red, true);
          clean(nb, blue, false);
          continue;
        }
        else if(board[nr.x][nr.y]==H){
          clean(nr, red, true);
          clean(nb, blue, false);
          if(board[nb.x][nb.y]==H){
            continue;
          }
          ans = Math.min(ans, count);
          return;
        } 
        else if(nr.x!=red.x || nr.y!=red.y || nb.x != blue.x || nb.y != blue.y){
          solve(nr, nb, (row)?false:true, count+1);
        }
        // cleanup
        clean(nr, red, true);
        clean(nb, blue, false);
      }
    }
  }

  public static Node move(Node node, int dir, boolean red){
      if(board[node.x][node.y]==H) return node;
      board[node.x][node.y]=S;
      while(board[node.x+dx[dir]][node.y+dy[dir]]==S){  
        node.x+=dx[dir];
        node.y+=dy[dir];
      }
      if(board[node.x+dx[dir]][node.y+dy[dir]] == H){
          node.x+=dx[dir];
          node.y+=dy[dir];
          return node;
      }
      if(red) board[node.x][node.y] = R;
      else board[node.x][node.y] = B;
      return node;
  }

  public static void clean(Node node, Node target, boolean red){

      if(board[node.x][node.y]!=H) board[node.x][node.y] = S;
      if(red) board[target.x][target.y] = R;
      else board[target.x][target.y] = B;
  }
}