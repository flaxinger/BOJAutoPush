/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

import org.w3c.dom.Node
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Arrays

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val N = readLine()!!.toInt()
    val map = Array(N+1){ mutableListOf<Int>()}
    repeat(N-1){
        val (E, T) = readLine()!!.split(" ").map{it.toInt()}
        map[E].add(T)
        map[T].add(E)
    }
    println(solve(map, 1, N))
}

fun solve(map: Array<MutableList<Int>>, root: Int, NodeCount: Int): Int{

    val vs = BooleanArray(NodeCount+1){false}
    val dp = Array(NodeCount+1){DP()}
    traverse(map, root, dp, vs)
    return Math.min(dp[root]!!.banal, dp[root]!!.influencer)
}

fun traverse(
    map: Array<MutableList<Int>>,
    node: Int,
    mapDP: Array<DP>,
    vs: BooleanArray
) {
    vs[node] = true
    for(child in map[node]!!){
        if(!vs[child]) {
            traverse(map, child, mapDP, vs)
            mapDP[node].influencer += Math.min(mapDP[child].banal, mapDP[child].influencer)
            mapDP[node].banal += mapDP[child].influencer
        }
    }
}

class DP(
    var influencer: Int = 1,
    var banal: Int = 0,
)