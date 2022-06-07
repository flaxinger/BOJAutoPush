/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

fun main(){
	
	var Target = 0
	var mapA = mutableMapOf<Int, Long>()
	var mapB = mutableMapOf<Int, Long>()
	var A = intArrayOf()
	var B = intArrayOf()

	fun input(){
		Target = readln().toInt()
		var AN = readln().toInt()
		A = readln().split(" ").map{i -> i.toInt()}.toIntArray()
		var BN = readln().toInt()
		B = readln().split(" ").map{i -> i.toInt()}.toIntArray()
	}

	fun constructMap(idx: Int, map: MutableMap<Int, Long>, arr: IntArray){
		if(idx==arr.size) return
		var sum = 0
		for(i in idx until arr.size){
			sum+=arr[i]
			map.put(sum, map.getOrElse(sum){0L}+1L)
		}
		constructMap(idx+1, map, arr)
	}

	fun solve(){
		constructMap(0, mapA, A)
		constructMap(0, mapB, B)
		var ans = 0L
		for(num in mapA.keys)
			ans+=mapB.getOrElse(Target-num){0} * mapA.getOrElse(num){0}
			
		println(ans)
	}


	input()
	solve()

}