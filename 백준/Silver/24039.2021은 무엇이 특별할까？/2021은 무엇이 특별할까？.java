import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

  static int N = 0;
  static ArrayList<Integer> prime;
  static boolean[] arr;
  public static void main (String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    StringTokenizer st = new StringTokenizer(br.readLine());

    arr = new boolean[151];
    Arrays.fill(arr, true);
    N = Integer.valueOf(st.nextToken());
    prime = new ArrayList<>();
    setPrime();
    for(int i = 0; i < prime.size()-1; i++){
      if(prime.get(i)*prime.get(i+1) > N){
        System.out.println(prime.get(i)*prime.get(i+1));
        return;
      }
    }
  }

  public static void setPrime(){

    int set;
    for(int i = 2; i <= 150; i++){
      if(arr[i]){
        prime.add(i);
        set = i*2;
        while(set<= 150){
          arr[set] = false;
          set+=i;
        }
      }
    }
  }
}