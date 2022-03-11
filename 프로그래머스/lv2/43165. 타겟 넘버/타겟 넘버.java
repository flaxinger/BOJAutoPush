class Solution {
    int ans = 0;
    int target;
    int[] numbers;
    public int solution(int[] numbers, int target) {
        this.target = target;
        this.numbers = numbers;
        trav(0, 0);
        return ans;
    }
    
    private void trav(int idx, int sum){
        if(idx==numbers.length){
            if(target == sum)
                ans++;
            return;
        }
        
        trav(idx+1, sum-numbers[idx]);
        trav(idx+1, sum+numbers[idx]);
    }
}