import java.util.*;
import java.lang.*;
import java.io.*;

class Main{


  public static void solve() throws java.lang.Exception {


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // StringTokenizer st = new StringTokenizer(br.readLine());
    Stack<Character> stack = new Stack<>();
    // Deque<Character> pm = new Deque<Character>();
    // Deque<Character> md = new Deque<Character>();
    String a = br.readLine();
    String ans = "";
    

    for(int i = 0; i < a.length(); i++){
      char c = a.charAt(i);
      if(c==')'){
        while(!stack.empty() && stack.peek() != '(') {
          ans+= stack.pop();
        }
        stack.pop();
      }
      else if(c >= 'A' && c <= 'Z') ans+= c;
      else if(c == '+' || c == '-'){
       
        while(!stack.empty() && stack.peek() != '('){
          ans += stack.pop();
        }
        stack.push(c);
      }
      else if(c == '*' || c == '/'){
        while(!stack.empty() && (stack.peek() == '*' || stack.peek() == '/')){
          ans += stack.pop();
        }
        stack.push(c);
      }
      else if(c == '(') stack.push(c);
    }
    while(!stack.empty()){
      if(stack.peek() == '(') stack.pop();
      else ans += stack.pop();
    }




    ArrayList<Character> asas = new ArrayList<Character>();
    asas.add('-');
    asas.add('+');
    asas.add('/');
    asas.add('*');
    Collections.sort(asas);
    System.out.println(ans);
  }

  public static void main(String[] args) throws java.lang.Exception{
    solve();
  } 
}