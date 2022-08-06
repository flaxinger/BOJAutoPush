/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import java.io.BufferedReader
import java.io.InputStreamReader

val dx = intArrayOf(1, -1, 0,  0)
val dy = intArrayOf(0, 0, 1, -1)

fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val T = readLine()!!.toInt()
    var result = ""
    repeat(T){
        var (R, C) = readLine()!!.split(" ").map{ it.toInt()}
        var board = mutableListOf<MutableList<Char>>()
        repeat(R){
            var s = readLine()!!
            board.add(s.toCharArray().toMutableList())
        }
          
        var keys_raw = readLine()!!.toCharArray().toMutableList()
        var keys = 1 shl 27
        if(keys_raw[0]!='0')
	        for(k in keys_raw)
	            keys = keys or k.intFromChar()
	    var vs = MutableList(R){ MutableList(C) { 0 } }
        var prev = 0
        var ans = 0

        while(prev != keys){
        	prev = keys
			ans+=solve(R, C, board, vs, keys)
			keys = updateKey(R, C, keys, vs)
        }
        result+="$ans\n"
    }
    println(result)
}

fun solve(R: Int, C: Int, board: MutableList<MutableList<Char>>, vs: MutableList<MutableList<Int>>, keys: Int): Int{
	var ans = 0
	for(i in 0 until C){
        if(board[0][i].canPass(keys))
            ans += traverse(0, i, board, vs, keys)
        if(board[R-1][i].canPass(keys))
            ans += traverse(R-1, i, board, vs, keys)
    }
    for(i in 0 until R){
        if(board[i][0].canPass(keys))
            ans += traverse(i, 0, board, vs, keys)
        if(board[i][C-1].canPass(keys))
            ans += traverse(i, C-1, board, vs, keys)
    }
    return ans
}

fun updateKey(R: Int, C: Int, key: Int, vs: MutableList<MutableList<Int>>): Int{
	var result = key
    for(i in 0 until C){
        result = result or vs[0][i] 
        result = result or vs[R-1][i] 
    }
    for(i in 0 until R){
    	result = result or vs[i][0] 
        result = result or vs[i][C-1] 
    }	
    return result
}

fun traverse(x: Int, y: Int, board: MutableList<MutableList<Char>>, vs: MutableList<MutableList<Int>>, keys: Int): Int{
    var acc = 0
    if(board[x][y] == '$'){
    	acc++
    	board[x][y] = '.'
	}
    var nx: Int
    var ny: Int
    var cur: Char
    vs[x][y] = vs[x][y] or keys
    if(board[x][y].isKey()){
		vs[x][y] = vs[x][y] or board[x][y].intFromChar()
	}
    for(i in 0 until 4){
        nx = x + dx[i]
        ny = y + dy[i]
        if(nx >= 0 && nx < board.size && ny >= 0 && ny < board[0].size){
        	cur = board[nx][ny]
            if((vs[x][y] or vs[nx][ny])!= vs[nx][ny] && cur.canPass(vs[x][y]))
            	acc += traverse(nx, ny, board, vs, vs[x][y])
        }
    }
    return acc
}

fun Char.intFromChar(): Int{
	if(this in 'a'..'z')
        return 1 shl this-'a'
    return 1 shl this-'A'
}
fun Char.isKey(): Boolean = this in 'a'..'z'
fun Char.isDoor(): Boolean = this in 'A'..'Z'
fun Char.canPass(keys: Int): Boolean{
	if(this.isKey() || this == '.' || this == '$')
		return true
	if(this.isDoor() && this.intFromChar() and keys != 0)
		return true
	return false
}