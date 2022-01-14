

import java.util.*;
import java.lang.*;
import java.io.*;


class Main
{

  public static void func() throws java.lang.Exception {

    long A, B, C, ans = 1;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    A = Long.parseLong(st.nextToken());
    B = Long.parseLong(st.nextToken());
    C = Long.parseLong(st.nextToken());

    while(B>0){
      if((B&1) > 0){
        ans = (ans*A)%C;
      }
      A = (A*A)%C;
      B = B >> 1;
    }
    System.out.println(ans);

  }
  
  public static void main (String[] args) throws java.lang.Exception
  {
    func();
  }
}