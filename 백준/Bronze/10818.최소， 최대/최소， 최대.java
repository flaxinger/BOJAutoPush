import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

  public static void main (String[] args) throws java.lang.Exception{
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.valueOf(st.nextToken());

    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;

    st = new StringTokenizer(br.readLine());
    int tmp = 0;
    for(int i =0;i < N; i++){
      tmp = Integer.valueOf(st.nextToken());

      min = min>tmp?tmp:min;
      max = max<tmp?tmp:max;
    }
    
    System.out.println(min+" "+max);
  }
}

