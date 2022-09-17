/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import java.io.BufferedReader
import java.io.InputStreamReader

val ENG = 2
val ING = 1
val GREATER = 1

fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val N = readLine()!!.toInt()
    val (I, E) = readLine()!!.split(" ").map{it.toInt()}
    val board = Array(N){IntArray(N)}
    val min = Math.min(E, I)
    if(N*N-E-I < minSpace(min, N)){
    	println(-1)
    	return
    }
    if(E>I){
	    fillArray(board, GREATER, ENG, E, N)
	    fillArray(board, 0, ING, I, N)
    }
    else{
	    fillArray(board, GREATER, ING, I, N)	
    	fillArray(board, 0, ENG, E, N)
    }
    println(1)
    for(bo in board){
    	for(b in bo){
    		print(b)
    	}
    	println()
    }
}

fun fillArray(board: Array<IntArray>, type: Int, studentType: Int, C: Int, N: Int){
	var cur = 0
	if(type==GREATER){
		var x = 0
		var y = 0
		while(cur < C){
			board[x][y] = studentType
			if(x==0 || y==N-1){
				if(y==N-1){
					y = x+1
					x = N-1
				}
				else{
					x = y+1
					y = 0
				}
			}
			else{
				x--
				y++
			}
			cur++
		}
	}
	else{
		var x = N-1
		var y = N-1
		while(cur < C){
			board[x][y] = studentType
			if(x==N-1){
				x = y-1
				y = N-1
			}
			else {
				x++
				y--
			}
			cur++
		}
	}
}


fun minSpace(n: Int, N: Int): Int{
	for(i in 1..N){
		if(i*(i+1)/2 >= n){
			return i+1
		}
	}
	return Int.MAX_VALUE
}
 



