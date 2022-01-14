

import java.util.*;
import java.lang.*;
import java.io.*;



class Main{

	static class Node{
		int start, end, cost;
		Node(int start, int end, int cost){
			this.start = start;
			this.end = end;
			this.cost = cost;
		}
	}
    static void union(int a, int b){
    	a = find(a);
    	b = find(b);
    	parent[a] = b;
    }
    
    static int find(int a){
    	if(parent[a] == a) return a;
    	return find(parent[a]);
    }
    
    
    static Node[] arr;
    static int V, E;
    static int[] parent;
    
    public static void main (String[] args) throws java.lang.Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		V = Integer.valueOf(st.nextToken());
		E = Integer.valueOf(st.nextToken());
        arr = new Node[E];
        parent = new int[V+1];
        int a, b, c, result = 0;

        for(int i =0;i < V+1; i++) parent[i] = i;
        for(int i =0;i < E; i++){
        	st = new StringTokenizer(br.readLine());
        	a = Integer.valueOf(st.nextToken());
        	b = Integer.valueOf(st.nextToken());
        	c = Integer.valueOf(st.nextToken());
        	arr[i] = new Node(a, b, c);
        }
        
        Arrays.sort(arr, (aa, bb)-> aa.cost-bb.cost);
        
        int one, two, idx = 0;
        while(V > 1){
        	one = arr[idx].start;
        	two = arr[idx].end;
        	if(find(one)!=find(two)){
        		union(one, two);
        		V--;
        		result+=arr[idx].cost;
        	}
        	idx++;
        }
        System.out.println(result);
    }
}