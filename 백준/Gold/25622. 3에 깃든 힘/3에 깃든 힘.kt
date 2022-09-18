/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val N = readLine()!!.toInt()
    val arrForWinning = MutableList(N+1){0}
    val board = MutableList(N+1){ mutableListOf<Int>()}
    repeat(N-1){
        var (X, Y) = readLine()!!.split(" ").map{it.toInt()}
        board[X].add(Y)
        board[Y].add(X)
        arrForWinning[X]++
        arrForWinning[Y]++
    }
    var root = 0
    var best = 0
    for(i in 1..N){
        if(arrForWinning[i]>best){
            best = arrForWinning[i]
            root = i
        }
    }

    var ans = mutableListOf<MutableList<Int>>()
    val vs = BooleanArray(N+1){false}
    traverseChildren(N, root, board, vs, ans)
    val sb = StringBuilder("")
    if(ans.size == N/3){
        sb.append("S\n")
        for(an in ans){
            for(a in an){
                sb.append("$a ")
            }
            sb.append("\n")
        }
        println(sb)
    }
    else
        println("U")
}

fun traverseChildren(N: Int, node: Int, board: MutableList<MutableList<Int>>, vs:BooleanArray, ans: MutableList<MutableList<Int>>): MutableList<Int>{
    vs[node] = true
    var cur = mutableListOf<Int>()
    for(child in board[node]){
        if(!vs[child]){
            cur.addAll(traverseChildren(N, child, board, vs, ans))
        }
    }
    cur.add(node)
    if(cur.size == 3){
        ans.add(cur)
        return mutableListOf()
    }
    else if(cur.size < 3){
        return cur
    }
    return mutableListOf()
}
