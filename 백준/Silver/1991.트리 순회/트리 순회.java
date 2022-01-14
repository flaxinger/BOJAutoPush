

import java.util.*;
import java.lang.*;
import java.io.*;


class Main
{
  static Map<Character, Character[]> map  = new HashMap<Character, Character[]>();
  static int N;

  // static class TreeNode{
  //   int val;
  //   TreeNode left;
  //   TreeNode right;
  //   TreeNode() {}
  //   TreeNode(int a){
  //     this.val = a;
  //     this.left = null;
  //     this.right = null;
  //   }
  // }
  
  
  public static void preorder(char node){
      char left = map.get(node)[0];
      char right = map.get(node)[1];
      System.out.printf("%s",node);
      if(left!='.') preorder(left);
      if(right!='.') preorder(right);
  }

  public static void inorder(char node){
      char left = map.get(node)[0];
      char right = map.get(node)[1];
      if(left!='.') inorder(left);
      System.out.printf("%s",node);
      if(right!='.') inorder(right);
  }


  public static void postorder(char node){
      char left = map.get(node)[0];
      char right = map.get(node)[1];
      if(left!='.') postorder(left);
      if(right!='.') postorder(right);
      System.out.printf("%s",node);
  }

  public static void func() throws java.lang.Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    String buff, buffarr[];
    for(int i = 0; i < N; i++){
        buff = br.readLine();
        // System.out.println(buff);
        map.put(buff.charAt(0), new Character[] {buff.charAt(2), buff.charAt(4)});
    }

    preorder('A');
    System.out.println();
    inorder('A');
    System.out.println();
    postorder('A');
  }
  
  public static void main (String[] args) throws java.lang.Exception
  {
    func();
  }
}