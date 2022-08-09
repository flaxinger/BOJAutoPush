/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import java.io.BufferedReader
import java.io.InputStreamReader

var best = 0
val dx = arrayOf(-1, -1, 0, 0)
val dy = arrayOf(-1, 1, -1, 1)
fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val T = readLine()!!.toInt()
    val vs = IntArray(11){0}
    val dp = Array(11){Array(11){mutableMapOf<Int, Int>()}}
    var result = ""
    repeat(T){
        var (X, Y) = readLine()!!.split(" ").map{ it.toInt()}
        var board = mutableListOf<BooleanArray>()
        vs.fill(0)
        dp.forEach{a -> a.forEach{b -> b.clear()}}
        repeat(X){
            board.add(readLine()!!.toCharArray().map{i -> if(i=='.') true else false}.toBooleanArray())            
        }
        result+="${solve(X, Y, board.toTypedArray(), vs, dp)}\n"
    }
    println(result)
}


fun solve(X: Int, Y: Int, board: Array<BooleanArray>, vs: IntArray, dp: Array<Array<MutableMap<Int, Int>>>): Int {
	return traverse(Point(0,0), X, Y, board, vs, dp)
}

fun traverse(p: Point, X: Int, Y: Int, board: Array<BooleanArray>, vs: IntArray, dp: Array<Array<MutableMap<Int, Int>>>): Int{
	if(p.x == X) return 0
	var state = vs[p.x]
	if(p.x>0){
		state = state or vs[p.x-1] shl Y
	}
	if(dp[p.x][p.y].containsKey(state))
		return dp[p.x][p.y][state]!!
	var best = 0
	var next = p.inc(X, Y)
	best = maxOf(best, traverse(next, X, Y, board, vs, dp))
	var nx = 0
	var ny = 0
	if(board[p.x][p.y]){
		for(i in 0..3){
			nx = p.x+dx[i]
			ny = p.y+dy[i]
			if(nx>=0 && nx < X && ny >= 0 && ny < Y && vs[nx].used(ny)){
				dp[p.x][p.y][state] = best
				return best
			}
		}
		vs[p.x] = vs[p.x].use(p.y)
		best = maxOf(best, 1+traverse(next, X, Y, board, vs, dp))
		vs[p.x] = vs[p.x].unuse(p.y)
	}
	dp[p.x][p.y][state] = best
	return best
}

class Point(
	var x: Int,
	var y: Int,
){
	fun inc(X: Int, Y: Int): Point{
		if(y+1==Y){
			return Point(x+1, 0)
		}
		else return Point(x, y+1)
	}
}

fun Int.used(n: Int) = (this and (1 shl n)) > 0
fun Int.use(n : Int) = this or (1 shl n)
fun Int.unuse(n: Int) = this and (1 shl n).inv()