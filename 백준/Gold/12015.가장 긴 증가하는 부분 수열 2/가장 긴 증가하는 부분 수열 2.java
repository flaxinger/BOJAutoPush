import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    int[] arr;
    int N;
    ArrayList<Integer> LIS = new ArrayList<>();
    N = Integer.valueOf(st.nextToken());
    arr = new int[N];
    st = new StringTokenizer(br.readLine());
    for(int i = 0;i < N; i++){
      arr[i] = Integer.valueOf(st.nextToken());
    }

    int s, e, mid;
    LIS.add(Integer.MIN_VALUE);
    for(int i = 0;i < N; i++){
        if(arr[i] > LIS.get(LIS.size()-1)){
          LIS.add(arr[i]);
        }
        else{
          s = 0;
          e = LIS.size()-1;
          while(s < e){
              mid = (s+e)>>1;
              if(LIS.get(mid) >= arr[i]){
                e = mid;
              }
              else{
                s = mid+1;
              }
          }
          LIS.set(e, arr[i]);
        }
    }

    System.out.println(LIS.size()-1);
  }
}