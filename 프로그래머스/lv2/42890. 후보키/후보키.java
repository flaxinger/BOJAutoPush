import java.util.*;

class Solution {
    
    private String[][] table;
    private int CN, TN; // Column Number, Tuple Number, Left Columns;
    private boolean[] use;  
    private boolean[] isUsed;
    private boolean[] buffUsed;
    private List<Integer> keys;
    private int ans;
    
    public int solution(String[][] relation) {
        keys = new ArrayList<>();
        TN = relation.length;
        table = relation;
        CN = relation[0].length;
        use = new boolean[CN];
        isUsed = new boolean[CN];
        buffUsed = new boolean[CN];
        ans = 0;
        
        int check = 0;
        while(++check <= CN){
            traverse(0, check, 0);
        }
        
        return ans;
    }
    
    private void traverse(int idx, int check, int numCols){
        if(numCols > check) return;
        Set<String> set = new HashSet<>();
        
        if(numCols == check){
            for(String[] tuple: table){
                String s = "";
                for(int i =0;i < use.length; i++){
                    if(use[i]){
                        s+=tuple[i];
                    }
                }
                set.add(s);
            }
            if(set.size() == TN){
                int a = 0;
                for(int i =0;i < use.length; i++){
                    if(use[i]){
                        a |= 1<<i;
                    }
                }
                for(int key: keys){
                    if((key&a) == key)
                        return;
                }
                keys.add(a);
                ans++;
            }
            return;
        }
        
        if(idx < CN){
            traverse(idx+1, check, numCols);
            use[idx] = true;
            traverse(idx+1, check, numCols+1);
            use[idx] = false;
        }
    }
}