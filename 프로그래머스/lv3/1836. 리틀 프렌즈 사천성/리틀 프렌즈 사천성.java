import java.util.*;

class Solution { 
    
    Map<Character, List<Pair>> map;
    int count, checker, orig;
    final String impossible = "IMPOSSIBLE";
    
    public String solution(int m, int n, String[] _board) {
        String answer = "";
        map = new HashMap<>();
        count = 0; checker = 0;
        char[][] board = init(m, n, _board);
        // System.out.println(count);
        while(check()){
            Response res = find(board);
            board = res.board;
            // printBoard(board);
            if(res.s!=null) answer+=res.s;
        }
        // System.out.println(answer);
        if(count > 0) return impossible;
        return answer;
    }
    
    private void printBoard(char[][] board){
        System.out.println("----Printing Board-----");
        for(char[] ch: board){
            for(char c: ch){
                System.out.printf("%c", c);
            }
            System.out.println();
        }
    }
    private boolean check(){
        if(count == checker)
            return false;
        checker = count;
        return true;
    }
    
    private Response find(char[][] board){
        // System.out.println(count);
        String result = "";
        List<Character> remList = new ArrayList<>();
        for(Map.Entry<Character, List<Pair>> e: map.entrySet()){
            // System.out.printf("---%c---\n", e.getKey());
            boolean ok = true;
            Pair start = new Pair(e.getValue().get(0)), end = new Pair(e.getValue().get(1));
            
            int xInc = 1, yInc = 1;
            if(start.y > end.y){
                 yInc = -1;
            }
            
            // try horizontal
            while(start.y!=end.y){
                if(board[start.x][start.y]!='.' && board[start.x][start.y] != e.getKey()){
                    ok = false;
                    break;
                }
                start.y+=yInc;
            }
            if(ok){
                while(start.x!=end.x){
                    if(board[start.x][start.y]!='.' && board[start.x][start.y] != e.getKey()){
                        ok = false;
                        break;
                    }
                    start.x+=xInc;
                }
                if(ok){
                    remList.add(e.getKey());
                }
            }
            if(!ok){
                start = new Pair(e.getValue().get(0));
                // try vertical;
                ok = true;
                while(start.x!=end.x){
                    if(board[start.x][start.y]!='.' && board[start.x][start.y] != e.getKey()){
                        ok = false;
                        break;
                    }
                    start.x+=xInc;
                }
                if(ok){
                    while(start.y!=end.y){
                        if(board[start.x][start.y]!='.' && board[start.x][start.y] != e.getKey()){
                            ok = false;
                            break;
                        }
                        start.y+=yInc;
                    }
                    if(ok){
                        remList.add(e.getKey());
                    }
                }
            }
        }
        if(remList.size() == 0) return new Response(null, board);
        Collections.sort(remList);
        for(Pair p : map.get(remList.get(0))){
            board[p.x][p.y] = '.';
        }
        map.remove(remList.get(0));
        count --;
        return new Response(remList.get(0), board);
    }
    
    private char[][] init(int n, int m, String[] _board){
        char[][] board = new char[n][m];
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = _board[i].charAt(j);
                if(isChar(board[i][j])){
                    if(!map.containsKey(board[i][j])){
                        map.put(board[i][j], new ArrayList<>());
                        count++;
                    }
                    map.get(board[i][j]).add(new Pair(i, j));
                }
            }
        }        
        return board;
    }
    
    private boolean isChar(char c){
        if(c>='A' && c <='Z')
            return true;
        return false;
    }
    
    private class Pair{
        int x, y; // arr[x][y]
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        Pair(Pair p){
            this.x = p.x;
            this.y = p.y;
        }
    }
    
    private class Response{
        Character s;
        char[][] board;
        Response(Character s, char[][]board){
            this.s = s;
            this.board = board;
        }
    }
    
}