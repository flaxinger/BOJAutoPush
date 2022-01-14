

import java.util.*;
import java.lang.*;
import java.io.*;


class Main
{
  public static class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    public TreeNode(){};
    public TreeNode(int val){
      this.val = val;
      this.left = null;
      this.right = null;
    }
  }
  static ArrayList<Integer> ino, posto;
  static Map<Integer, Integer> map;
  static int N, idx;

  public static TreeNode build(int start, int end){

      if(idx < 0 || start > end) return null;
      TreeNode node = new TreeNode(posto.get(idx));
      int mid = map.get(node.val);  
      idx--;
      node.right = build(mid+1, end);
      node.left = build(start, mid-1);
      return node;
  }

  public static void spit(TreeNode node){

    System.out.printf("%d ", node.val);
    if(node.left != null) spit(node.left);
    if(node.right != null) spit(node.right);
  }

  public static void func() throws java.lang.Exception {

    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    ino = new ArrayList<Integer>();
    posto = new ArrayList<Integer>();
    map = new HashMap<Integer, Integer>();
    int buff;

    for(int i = 0; i < N; i++){
      buff = Integer.parseInt(st.nextToken());
      ino.add(buff);
      map.put(buff, i);
    }  
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < N; i++){
      posto.add(Integer.parseInt(st.nextToken()));
    }  
    idx = posto.size()-1;
    // System.out.println(idx);
    TreeNode root = build(0, idx);
    spit(root);
  }
  
  public static void main (String[] args) throws java.lang.Exception
  {
    func();
  }
}