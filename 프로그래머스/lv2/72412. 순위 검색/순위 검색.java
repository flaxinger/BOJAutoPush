import java.util.*;

class Solution {
    
    Map<String, List<Integer>> map;
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        int count = 0;
        map = new HashMap<>();
        for(String s: info){
            addDeveloper(s);
        }
        for(Map.Entry<String, List<Integer>> e: map.entrySet()){
            e.getValue().sort((a, b)->Integer.compare(b, a));   
        }
        for(int i = 0;i < query.length; i++){
            String[] arr= query[i].split(" ");
            String q = arr[0]+" "+arr[2]+" "+arr[4]+" "+arr[6];
            if(map.containsKey(q))
                answer[i]=findNum(map.get(q), Integer.valueOf(arr[7]));
        }
        return answer;
    }
    
    private int findNum(List<Integer> list, int num){
        int s = 0, e = list.size()-1, mid = 0;
        if(list.size() == 0 || list.get(0)< num) return 0;
        while(s <= e){
            mid = (s+e)/2;
            if(num <= list.get(mid)){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return s;
    }

        
    private void addDeveloper(String s){
        String[] sarr = s.split(" ");
        String lang = sarr[0], position = sarr[1], experience = sarr[2], food = sarr[3];
        List<String> list = new ArrayList<>();
        
        list.add(lang+" "+position+" "+experience+" "+food);
        list.add("- "+position+" "+experience+" "+food);
        list.add(lang+" - "+experience+" "+food);
        list.add(lang+" "+position+" - "+food);
        list.add(lang+" "+position+" "+experience+" -");
        list.add("- - "+experience+" "+food);
        list.add(lang+" - - "+food);
        list.add(lang+" "+position+" - -");
        list.add("- "+position+" - "+food);
        list.add("- "+position+" "+experience+" -");
        list.add(lang+" - "+experience+" -");
        list.add("- - - -");
        list.add(lang+" - - -");
        list.add("- "+position+" - -");
        list.add("- - "+experience+" -");
        list.add("- - - "+food);
        
        for(String str: list){
            map.putIfAbsent(str, new ArrayList<>());
            map.get(str).add(Integer.valueOf(sarr[4]));
        }
    }
}