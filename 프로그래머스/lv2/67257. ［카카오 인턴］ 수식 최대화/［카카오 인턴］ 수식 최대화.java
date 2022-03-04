import java.util.*;

class Solution {
    char[][] order = {
        {'+', '-', '*'},
        {'+', '*', '-'},
        {'-', '*', '+'},
        {'-', '+', '*'},
        {'*', '-', '+'},
        {'*', '+', '-'}
    };
    
    List<Character> op;
    List<Long> num;
    public long solution(String expression) {
        long answer = 0;
        op = new ArrayList<>();
        num = new ArrayList<>();
        
        parse(expression);
        
        for(int i =0;i < 6; i++){
            answer = Math.max(answer, Math.abs(calc(order[i])));
        }
        return answer;
    }
    
    public long calc(char[] arr){
        List<Character> op1 = new ArrayList<>();
        List<Long> num1 = new ArrayList<>();
        for(Character c: op)
            op1.add(c);
        for(Long l: num)
            num1.add(l);
        int length = op1.size();
        for(int i =0;i < 3; i++){
            for(int j =0; j < length; j++){
                if(op1.get(j) == arr[i]){
                    num1.set(j, operation(op1.get(j), num1.get(j), num1.get(j+1)));
                    op1.remove(j);
                    num1.remove(j+1);
                    j--;
                    length--;
                }
            }    
        }
        return num1.get(0);
    }
    
    public long operation(char oper, long x, long y){
        switch(oper){
            case('*'):
                return x*y;
            case('-'):
                return x-y;
            case('+'):
                return x+y;
            default:
                System.out.println("error");
                return 0;
        }
    }
    
    private void parse(String ex){
        
        char c = ex.charAt(0);
        if(c == '*' || c == '-' || c == '+'){
            op.add(c);
            parse(ex.substring(1));
        }
        else{
            long n = 0;
            while(ex.length() > 0 && isNum(ex.charAt(0))){
                n*=10;
                n+=ex.charAt(0)-'0';
                ex = ex.substring(1);
            }
            num.add(n);
            if(ex.length() == 0) return;
            parse(ex);
        }
            
    }
    
    private boolean isNum(char c){
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
    
}