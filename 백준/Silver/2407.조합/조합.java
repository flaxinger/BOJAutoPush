import java.lang.*;
import java.io.*;
import java.util.*;
import java.math.*;


class Main{

  static BigInteger[] arr;


  public static void solve() throws java.lang.Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int N = Integer.valueOf(st.nextToken());
    int M = Integer.valueOf(st.nextToken());

    arr = new BigInteger[N+1];

    arr[0] = new BigInteger("1");

    for(int i = 1; i <= N; i++)
      arr[i] = arr[i-1].multiply(new BigInteger(Integer.toString(i)));

    System.out.println(arr[N].divide(arr[M].multiply(arr[N-M])));

  }
  public static void main(String[] args) throws java.lang.Exception {
    solve();
  }
}