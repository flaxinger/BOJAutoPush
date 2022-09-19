import java.io.BufferedReader
import java.io.InputStreamReader

fun main()= with(BufferedReader(InputStreamReader(System.`in`))){

    val (_N, M, K) = readLine().split(" ").map { it.toInt()}

    var N = 2
    while(N < _N+1){N*=2}
    N++
    val arr = LongArray(N)
    val tree = LongArray(N)

    for(i in 1.._N)
        arr[i] = readLine()!!.toLong()

    buildTree(tree, arr)

    val sb = StringBuilder("")
    repeat(M+K){
        val (a, b, c) = readLine().split(" ")
        when(a){
            "1" -> {
                val idx = b.toInt()
                val num = c.toLong()
                addTree(tree, idx, num - arr[idx] )
                arr[idx] = num
            }
            "2" -> {
                sb.append("${findPartialSum(tree, b.toInt()-1, c.toInt())}\n")
            }
        }
    }
    print(sb)
}

fun buildTree(tree: LongArray, arr: LongArray){
    for(i in 1 until arr.size){
        addTree(tree, i, arr[i])
    }
}

fun addTree(tree: LongArray, _idx: Int, num: Long){

    var idx = _idx
    while(idx < tree.size){
        tree[idx]+=num
        idx += (idx and -idx)
    }

}

fun findPartialSum(tree: LongArray, s: Int, e: Int)
    = findPartialSum(tree, e) - findPartialSum(tree, s)


fun findPartialSum(tree: LongArray, _e: Int): Long{
    var e = _e
    var ans = 0L
    while(e > 0){
        ans+=tree[e]
        e -= (e and -e)
    }
    return ans
}