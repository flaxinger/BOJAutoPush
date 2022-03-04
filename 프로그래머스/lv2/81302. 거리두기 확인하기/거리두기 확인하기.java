class Solution {

    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, -1, 0, 1};

    public int[] solution(String[][] places) {
        int[] answer = new int[5];

        for(int i = 0;i < 5; i++){
            answer[i] = calc(places[i])==1?0:1;
        }
        return answer;
    }

    private int calc(String[] arr){

        int result = 0;
        for(int i = 0;i < arr.length; i++){
            for(int j = 0;j < arr[i].length(); j++){
                if(arr[i].charAt(j) == 'P')
                    result|=traverse(arr, i, j, 0, 0);
            }
        }
        return result;

    }

    private int traverse(String[] arr, int x, int y, int dist, int ban){

        int result = 0;
        int nx, ny;
        for(int i = 0;i < 4; i++){
            if(dist > 0 && i==ban) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(valid(nx) && valid(ny)){
                if(arr[nx].charAt(ny) == 'O' && dist < 1)
                    result|=traverse(arr, nx, ny, dist+1, (i+2)%4);
                else if(arr[nx].charAt(ny) == 'P')
                    return 1;
            }
        }
        return result;
    }

    private boolean valid(int n){
        if(n >= 0 && n < 5) return true;
        return false;
    }
} 