import java.util.*;

class Solution {
    
    private int CAP = 1, LOW = 2, NONE = 3;
    private boolean[] check = new boolean[26];
    private String IV = "invalid";
    private List<String> invalid = Arrays.asList(IV);
    
    public String solution(String s) {
        String ans = "";
        List<String> list = solve(s);
        if(list.get(list.size()-1) == IV) return IV;
        else{
          for(int i = 0; i < list.size()-1; i++){
              ans+=list.get(i)+" ";
          }
          ans+=list.get(list.size()-1);
        }
        return ans;
    }
    
    
    private List<String> solve(String s){

      List<String> list = new ArrayList<>();
      if(s.length() == 0) return list;

      switch(charState(s.charAt(0))){
        case 1:
          list = case1(s);
          if(isIV(list))
            list = case2(s);
          return list;
        case 2:
          return case3(s);
        case 3:
          return invalid;
        default:
          return invalid;      
      }
    }

    private List<String> case1(String s){
      List<String> list = new ArrayList<>();
      int idx = 0, N = s.length();
      String buff = "";

      while(idx < N && charState(s.charAt(idx)) == CAP){
        buff+=s.charAt(idx);
        idx++;
      }
      list.add(buff);
      if(idx < N)
        list.addAll(solve(s.substring(idx)));
      if(isIV(list) && buff.length() > 1){
        list = new ArrayList<>();
        list.add(buff.substring(0, buff.length()-1));
        if(buff.length()-1 < N){
          list.addAll(solve(s.substring(buff.length()-1)));
          return list;
        }
      }
      return list;
    }

    private List<String> case2(String s){
      List<String> list = new ArrayList<>();
      int idx = 0, N = s.length();
      if(N < 2 || 
        charState(s.charAt(0)) != CAP || 
        charState(s.charAt(1)) != LOW ||
        !visit(s.charAt(1))) {
        return invalid;
      }
      char inbetween = s.charAt(1);
      String buff = "";
      while(idx+1 < N && charState(s.charAt(idx)) == CAP && s.charAt(idx+1) == inbetween){
        buff+=s.charAt(idx);
        idx+=2;
      }
      if(idx < N && charState(s.charAt(idx)) == CAP){
        buff+=s.charAt(idx++);
        list.add(buff);
        if(idx < N)
          list.addAll(solve(s.substring(idx)));
        unvisit(inbetween);
        return list;
      }
      unvisit(inbetween);
      return invalid;
    }

    private List<String> case3(String s){
      List<String> list = new ArrayList<>();
      int N = s.length(), idx = 0;
      String buff = "";
      if(N <3 || 
        charState(s.charAt(idx)) != LOW || 
        charState(s.charAt(idx+1)) != CAP ||
        !visit(s.charAt(idx))){
        return invalid;
      }
      char outer = s.charAt(0);
      boolean extra = false;
      idx++;
      while(idx < N && s.charAt(idx) != outer){
        buff+=s.charAt(idx);
        if(charState(s.charAt(idx)) == LOW) extra = true;
        idx++;
      }
      if(idx == N || s.charAt(idx) != outer){
        unvisit(outer);
        return invalid;
      }
      if(extra){
        buff = "";
        if(charState(s.charAt(2))!=LOW || !visit(s.charAt(2))){
            unvisit(outer);
            return invalid;
        }  
        char inner = s.charAt(2);
        for(int i = 1; i < idx; i++){
            if(i%2 == 1 && charState(s.charAt(i)) == CAP){
                buff+=s.charAt(i);
            }
            else if(i%2 != 0 || s.charAt(i) != inner){
                unvisit(inner);
                unvisit(outer);
                return invalid;
            }
        }
        list.add(buff);
      }
      else
        list.add(buff);
      if(++idx < N){
        list.addAll(solve(s.substring(idx)));
      }
      unvisit(outer);
      return list;
    }

    private int charState(char c){
      if(c>='a' && c <= 'z')
        return LOW;
      if(c>='A' && c <= 'Z')
        return CAP;
      return NONE;
    }

    private boolean visit(char c){
      if(check[c-'a']){
        return false;
      }
      check[c-'a'] = true;
      return true;
    }

    private void unvisit(char c){
      if(!check[c-'a']){
        System.out.println("Error check[i] needs to be true but is false");
        return;
      }
      check[c-'a'] = false;
    }

    private boolean isIV(List<String> list){
      if(list.size() == 0)
        return false;
      return list.get(list.size()-1).equals(IV);
    }
    
}