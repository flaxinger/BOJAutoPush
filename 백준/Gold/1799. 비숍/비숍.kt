/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/
import java.util.*

var initN = 0
var N = 0
var initBoard = mutableListOf<IntArray>()
var board = Array(0) {IntArray(0)}
var check = IntArray(0)
var best = 0
val POSSIBLE = 1
val PADDING = 2

fun input(){
	initN = readln().toInt()
	repeat(initN){
		initBoard.add(readln().split(" ").map{it.toInt()}.toIntArray())
	}
	N = initN*2-1
	check = IntArray(N){-1}
	board = Array(N) {IntArray(N) {PADDING}}
}

fun solve(){
	transpose()
	search(0, 0)
	println(best)
}

fun transpose(){
	var nx = 0;	var ny = N/2;	var x = 0; var y = 0; var found = false; var temp = 0
	
	board[nx][ny] = initBoard[x][y]
	board[N-1][ny] = initBoard[initN-1][initN -1]
	
	nx = nx+1; ny = ny-1; x = 1; y = 0

	while(x!=initN-1 || y != initN-1){
		board[nx][ny] = initBoard[x][y]
		// println("board[$nx][$ny] = initBoard[$x][$y]")
		if(x > 0 && y < initN-1){
			x--
			y++
		}
		else{
			if(y < initN-1){
				x = y+1
				y = 0
			}
			else{
				temp = x
				x = y
				y = temp+1
			}
		}
		found = false;
		for(j in ny+1 until N-Math.max(0, nx-N/2)){
			if((j!=0 && board[nx-1][j-1] != PADDING)|| (j!=N-1 && board[nx-1][j+1] != PADDING)){
				found = true
				ny = j
				break
			}
		}
		if(!found){
			nx++
			for(j in Math.max(0, nx-N/2) until N){
				if((j!=0 && board[nx-1][j-1] != PADDING)|| (j!=N-1 && board[nx-1][j+1] != PADDING)){
					ny = j
					break
				}
			}
		}
	}
}

fun search(idx: Int, point: Int){

	if(best>=point+N-idx) return
	if(idx==N){
		best = Math.max(best, point)
		return 
	}
	search(idx+1, point)
	var canPlace = false
	for(i in 0 until N){
		if(board[idx][i] == POSSIBLE){
			canPlace = true
			for(j in 0 until idx){
				if(check[j] == i){
					canPlace = false
					break;
				}
			}	
			if(canPlace){
				check[idx] = i
				search(idx+1, point+1)
				check[idx] = -1
			}
		}
	}
}

fun main(){
	input()
	solve()
}