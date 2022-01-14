import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static char[][] board;
  static int R, C;
  static Set<Character> set;
  static int[] dx = new int[]{1, 0, -1, 0};
  static int[] dy = new int[]{0, 1, 0, -1};
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    String buff;
    R = Integer.valueOf(st.nextToken());
    C = Integer.valueOf(st.nextToken());
    set = new HashSet<>();
    board = new char[R][C];

    for(int i = 0;i < R; i++){
      st = new StringTokenizer(br.readLine());
      buff = String.valueOf(st.nextToken());
      for(int j = 0; j < C; j++){
        board[i][j] = buff.charAt(j);
      }
    }

    System.out.println(solve(0, 0));
  }

  public static int solve(int x, int y){
    int nx = 0, ny = 0, best = 1;
    set.add(board[x][y]);
    for(int i = 0; i < 4; i++){
      nx = x+dx[i];
      ny = y+dy[i];
      if(nx >= 0 && nx < R && ny >= 0 && ny < C && !set.contains(board[nx][ny])){
        best = Math.max(best, solve(nx, ny)+1);
      }
    }
    set.remove(board[x][y]);
    return best;
  }
}