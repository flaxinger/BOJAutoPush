/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

fun main(){
	var S1 = ""
	var S2 = ""
	var N = 0
	var M = 0
	val START = 0
	val UP = 1
	val LEFT = 2
	val DIAG = 3

	fun input(){
		S1 = readln()
		S2 = readln()
		N = S1.length
		M = S2.length
	}


	fun solve(){
		var dp = Array(N){Array(M){IntArray(2)}}
		
		if(S1==""||S1==""){
			println(0)
			return
		}

		if(S1[0]==S2[0]){
			dp[0][0][0] = 1
			for(i in 1 until N){
				dp[i][0][0] = 1
				dp[i][0][1] = UP
			}
			for(j in 1 until M){
				dp[0][j][0] = 1
				dp[0][j][1] = LEFT
			}
		}
		else{
			for(i in 1 until N){
				if(S1[i]==S2[0]){
					dp[i][0][0] = 1
					for(j in i+1 until N){
						dp[j][0][0] = 1
						dp[j][0][1] = UP
					}
					break
				}
			}
			for(i in 1 until M){
				if(S1[0] == S2[i]){
					dp[0][i][0] = 1
					for(j in i+1 until M){
						dp[0][j][0] = 1
						dp[0][j][1] = LEFT
					}
					break
				}
			}
		}

		for(i in 1 until N){
			for(j in 1 until M){
				dp[i][j][0] = dp[i-1][j-1][0]
				dp[i][j][1] = DIAG
				if(S1[i]==S2[j])
					dp[i][j][0]++
				if(dp[i-1][j][0] > dp[i][j][0]){
					dp[i][j][0] = dp[i-1][j][0]
					dp[i][j][1] = UP
				}
				if(dp[i][j-1][0] > dp[i][j][0]){
					dp[i][j][0] = dp[i][j-1][0]
					dp[i][j][1] = LEFT
				}
			}
		}


		if(dp[N-1][M-1][0] == 0){
			println(0)
		}
		else{
			var x = N-1
			var y = M-1
			var ans = StringBuilder()
			while(dp[x][y][1]!=START){
				when(dp[x][y][1]){
					UP ->{
						x--
					}
					LEFT -> {
						y--
					}
					DIAG -> {
						x--
						y--
						if(dp[x][y][0] < dp[x+1][y+1][0]){
							ans.insert(0, S1[x+1])
						}
					}
				}
			}
			if(dp[x][y][0]==1){
				ans.insert(0, S1[x])
			}
			println(ans.length)
			println(ans)
		}
	}	

	input()
	solve()

}