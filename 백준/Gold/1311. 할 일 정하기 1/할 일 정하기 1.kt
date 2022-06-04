/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/
import java.util.*

fun solve(){

	val N = readln().toInt()
	val M = 1 shl N
	val MAX = Int.MAX_VALUE shr 1
	val board = mutableListOf<IntArray>()
	val dp = Array(N){IntArray(M){MAX}}
	var candidates = mutableSetOf<Int>()
	var cur: IntArray
	
	repeat(N){
		board.add(readln().split(" ").map{it.toInt()}.toIntArray())
	}

	for(i in 0 until N){
		dp[0][1 shl i] = board[0][i]
		candidates.add(1 shl i)
	}
	for(i in 1 until N){
		cur = candidates.toIntArray()
		candidates.clear()
		for(c in cur){
			for(j in 0 until N){
				if(c and (1 shl j) == 0){
					dp[i][c or (1 shl j)] = Math.min(
						dp[i][c or (1 shl j)],
						dp[i-1][c]+board[i][j]
						)
					candidates.add(c or (1 shl j))
				}
			}
		}
	}
	var ans = MAX
	for(candidate in candidates){
		ans = Math.min(ans, dp[N-1][candidate])
	}
	println(ans)
}

fun main(){
	solve()
}