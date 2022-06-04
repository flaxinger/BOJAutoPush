/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/


fun solve(){

	val N = readln().toInt()
	val M = 1 shl N
	val MAX = Int.MAX_VALUE shr 1
	val board = mutableListOf<IntArray>()
	val dp = Array(N){IntArray(M){MAX}}
	repeat(N){
		board.add(readln().split(" ").map{it.toInt()}.toIntArray())
	}

	for(i in 0 until N){
		dp[0][1 shl i] = board[0][i]
	}
	for(i in 1 until N){
		for(j in 0 until N){
			for(k in 0 until M){
				if((k and (1 shl j)) == 0){
					dp[i][k or (1 shl j)] = Math.min(
						dp[i][k or (1 shl j)],
						dp[i-1][k]+board[i][j]
						)
				}
			}
		}
	}
	var ans = MAX
	for(i in 0 until M){
		ans = Math.min(ans, dp[N-1][i])
	}
	println(ans)
}



fun main(){
	solve()
}



