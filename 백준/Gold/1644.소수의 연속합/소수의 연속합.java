import java.util.*;
import java.lang.*;
import java.io.*;


class Main{
  
  static int N;
  static boolean[] prime;
  static ArrayList<Integer> arr;
  public static void main(String[] args) throws java.lang.Exception{

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
  
    N = Integer.valueOf(st.nextToken());
    prime = new boolean[N+1];
    arr = new ArrayList<>();
	BuildPrime();
	
	int ans = 0, sum = 0, s = 0, e = 1, S = arr.size();
	if(arr.size()>0) sum = arr.get(0);
	while(e<S || sum>=N){
		if(sum == N){
			ans++;
			if(e!=S){
				sum +=arr.get(e);
				e++;
			}
			else{
				break;
			}
		}
		else if(sum < N){
			sum+=arr.get(e);
			e++;
		}
		else if(sum > N){
			sum-=arr.get(s);
			s++;
		}
	}
	System.out.println(ans);
  }
  
  public static void BuildPrime(){
  	
  	Arrays.fill(prime, true);
  	for(int i = 2;i < prime.length; i++){
  		if(prime[i]){
  			arr.add(i);
  			int id = i*2;
  			while(id < prime.length){
  				prime[id]=false;
  				id+=i;
  			}
  		}
  	}
  }
}