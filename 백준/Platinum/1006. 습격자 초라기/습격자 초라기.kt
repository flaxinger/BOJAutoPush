
/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import java.io.BufferedReader
import java.io.InputStreamReader

val MAX: Short = 20001

fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val T = readLine()!!.toInt()
    var result = ""
    var vs = Array(2){BooleanArray(10001){false}}
	var dp = Array(10001){ShortArray(10001){MAX}}
    repeat(T){
        var (N, W) = readLine()!!.split(" ").map{ it.toInt()}
        var board = mutableListOf<ShortArray>()
        repeat(2){
            board.add(readLine()!!.split(" ").map{i -> i.toShort()}.toShortArray())            
        }
        result+="${solve(N, W, board.toTypedArray(), vs, dp)}\n"
    }
    println(result)
}


// finds the minimum for four logical base cases
fun solve(N: Int, W: Int, board: Array<ShortArray>, vs: Array<BooleanArray>, dp: Array<ShortArray>): Short {

	resetVSDP(vs, dp, N)
	var best: Short = myMin(MAX, findMin(0, 0, N, W, board, vs, dp))
	// print2D(dp, N, 1)
	if(board[0][0]+board[0][N-1]<=W){
		resetVSDP(vs, dp, N)
		vs[0][N-1] = true
		best = myMin(best, findMin(1, 0, N, W, board, vs, dp).inc())
		// print2D(dp, N, 2)
		if(board[1][0]+board[1][N-1]<=W){
			resetVSDP(vs, dp, N)
			vs[0][N-1] = true
			vs[1][0] = true
			vs[1][N-1] = true
			best = myMin(best, findMin(1, 1, N, W, board, vs, dp).inc().inc())
			// print2D(dp, N, 3)
		}
	}
	if(board[1][0]+board[1][N-1]<=W){
		resetVSDP(vs, dp, N)
		vs[1][0] = true
		vs[1][N-1] = true
		best = myMin(best, findMin(0, 1, N, W, board, vs, dp).inc())
		// print2D(dp, N, 4)
	}
	return best
}

// x is board[0][x] y is board[1][y]
fun findMin(x: Int, y: Int, N: Int, W: Int, board: Array<ShortArray>, vs: Array<BooleanArray>, dp: Array<ShortArray>): Short{

	if((x>=N || vs[0][x]) && (y>=N || vs[1][y])) return 0
	if(dp[x][y]<MAX) return dp[x][y]
	if(!vs[0][x] && x< N && x<= y){
		var c1 = findMin(x+1, y, N, W, board, vs, dp)
		var c2 = if(x+1<N && board[0][x]+board[0][x+1]<=W && !vs[0][x+1]) findMin(x+2, y, N, W, board, vs, dp) else MAX
		var c3 = if(x==y && y<N && board[0][x]+board[1][y]<=W && !vs[1][y]) findMin(x+1, y+1, N, W, board, vs, dp) else MAX
		dp[x][y] = manyMin(c1, c2, c3).inc()
		return dp[x][y]
	}
	else{
		var c1 = findMin(x, y+1, N, W, board, vs, dp)
		var c2 = if(y+1<N && board[1][y]+board[1][y+1]<=W && !vs[1][y+1]) findMin(x, y+2, N, W, board, vs, dp) else MAX
		dp[x][y] = myMin(c1, c2).inc()
		return dp[x][y]
	}
}


fun resetVSDP(vs: Array<BooleanArray>, dp: Array<ShortArray>, N: Int): Unit{
	vs.forEach{i -> i.fill(false, 0 , N+1)}
	dp.forEach{i-> i.fill(MAX, 0, N+1)}
}
fun manyMin(c1: Short, c2: Short, c3: Short): Short{
	return myMin(c1, myMin(c2, c3))
}
fun myMin(a: Short, b:Short): Short{
	return if(a < b) a else b
}

fun print2D(dp: Array<ShortArray>, N: Int, t: Int){
	println("\n-----------------\nthis is try $t\n-------------------")
	for(j in 0..N){
		var v = dp[j]
		for(i in 0..N){
			print("${if(v[i]==MAX) '-' else v[i]}\t")
		}
		println()
	}
}