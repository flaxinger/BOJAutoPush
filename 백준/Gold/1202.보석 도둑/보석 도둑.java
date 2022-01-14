import java.util.*;
import java.lang.*;
import java.io.*;

class Main{

    static class Jewel{
        int weight, value;
        Jewel(int weight, int value){
            this.weight = weight;
            this.value = value;
        }
    }

    static int N, K;
    static PriorityQueue<Jewel> pq, possible;
    static long[] bag;
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.valueOf(st.nextToken());
        K = Integer.valueOf(st.nextToken());
        pq = new PriorityQueue<>((a, b)->{
            return Integer.compare(a.weight, b.weight);
        });
        possible = new PriorityQueue<>((a, b)->{
            return Integer.compare(b.value, a.value);
        });
        bag = new long[K];
        int w, c;
        for(int i =0;i < N; i++){
            st = new StringTokenizer(br.readLine());
            pq.add(new Jewel(Integer.valueOf(st.nextToken()), Integer.valueOf(st.nextToken())));
        }

        for(int i =0;i < K; i++){
            st = new StringTokenizer(br.readLine());
            bag[i] = Long.valueOf(st.nextToken());
        }

        long ans = 0L;
        Arrays.sort(bag);

        for(int i =0;i < K; i++){
            while(!pq.isEmpty() && pq.peek().weight <= bag[i]){
                possible.add(pq.poll());
            }
            if(!possible.isEmpty()) ans+=possible.poll().value;
        }

        System.out.println(ans);
    }   
}