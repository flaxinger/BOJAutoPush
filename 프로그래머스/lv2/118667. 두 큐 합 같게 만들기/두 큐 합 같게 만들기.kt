class Solution {
    fun solution(queue1: IntArray, queue2: IntArray): Int {
        
        var arr = LongArray(queue1.size + queue2.size)
        val N = arr.size
        var half = 0L
        var sum = 0L
        for(i in 0 until queue1.size){
            half+=queue1[i].toLong()
            sum+=queue1[i].toLong()
            arr[i] = queue1[i].toLong()
        }
        for(i in 0 until queue2.size){
            sum+=queue2[i].toLong()
            arr[i+queue1.size] = queue2[i].toLong()
        }

        
        if(sum%2!=0L) return -1
        val target = sum/2
        if(half == target) return 0
        
        var a = 0
        var b = queue1.size
        var count = 0
        while(count<2*N){
            if(half==target) return count
            if(half < target || a==b){
                half+=arr[b]
                b=b.addOne(N)
            }
            else{
                half-=arr[a]
                a=a.addOne(N)
            }
            count++
        }
        return -1
    }
    
}

fun Int.addOne(MAX: Int): Int {
    return (this+1)%MAX
}