import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer;
        Map<String, Genre> map = new HashMap<>();
        for(int i = 0; i < genres.length; i++){
            map.putIfAbsent(genres[i], new Genre());
            map.get(genres[i]).add(new Song(i, plays[i]));
            map.get(genres[i]).count+=plays[i];
        }
        PriorityQueue<Genre> pq = new PriorityQueue<>((a, b)->{
            return Integer.compare(b.count, a.count);
        });
        for(Map.Entry<String, Genre> e: map.entrySet()){
            pq.add(e.getValue());
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        while(pq.size()> 0){
            Genre tmp = pq.poll();
            for(int i =0;i < 2; i++){
                Song stmp = tmp.get();
                if(stmp!=null){
                    ans.add(stmp.id);
                }
            }
        }
        
        Integer[] buff =ans.toArray(new Integer[ans.size()]);
        answer = new int[buff.length];
        for(int i = 0; i < buff.length; i++)
            answer[i] = buff[i];
        return answer;
    }

    private class Song{
        int id, count;
        Song(int id, int count){
            this.id = id;
            this.count = count;
        }
    }
    
    private class Genre{
        int count = 0;
        PriorityQueue<Song> pq = new PriorityQueue<>((a, b) ->{
            if(a.count!=b.count)
                return Integer.compare(b.count, a.count);
            return Integer.compare(a.id, b.id);
        });
        Genre(){};
        void add(Song song){
            this.pq.add(song);
        }
        Song get(){
            if(pq.size() == 0) return null;
            return pq.poll();
        }
    }
}