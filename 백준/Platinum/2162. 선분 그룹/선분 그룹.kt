/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

class Point(
	val x: Long,
	val y: Long
)

class Line(
	_x1: Long,
	_y1: Long, 
	_x2: Long, 
	_y2: Long,
){
	val p1 = Point(_x1, _y1)
	val p2 = Point(_x2, _y2)

	fun isCross(l: Line): Boolean{
		val a = ccw(p1, p2, l.p1) * ccw(p1, p2, l.p2)
	  	val b = ccw(l.p1, l.p2, p1) * ccw(l.p1, l.p2, p2)

	  	// println("${this}, $l is $a, and $b - isOverlap = ${isOverlap(l)}")
	  	if(a==0L && b== 0L)
	  		return isOverlap(l)
	  	return a<=0&& b<=0
	}

	fun ccw(a: Point, b:Point, c:Point): Long{
		return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)
	}

	fun isOverlap(l: Line): Boolean{
		if(Math.max(p1.x, p2.x) < Math.min(l.p1.x, l.p2.x)) return false
		if(Math.max(l.p1.x, l.p2.x) < Math.min(p1.x, p2.x)) return false
		if(Math.max(p1.y, p2.y) < Math.min(l.p1.y, l.p2.y)) return false
		if(Math.max(l.p1.y, l.p2.y) < Math.min(p1.y, p2.y)) return false
		return true
	}

	override fun toString() = "(${p1.x}, ${p1.y}), (${p2.x}, ${p2.y})"
}

fun main(){
	
	var N = 0
	var list = mutableListOf<Line>()
	var parent = intArrayOf()

	fun input(){
		N = readln().toInt()
		parent = IntArray(N, {i -> i})
		list.clear()
		repeat(N){
		 	var(a, b, c, d) = readln().split(" ").map{i -> i.toLong()}
		 	if(a < c) list.add(Line(a, b, c, d))
		 	else list.add(Line(c, d, a, b))
		}
		// for(line in list){
		// 	println("(${line.x1}, ${line.y1}) (${line.x2}, ${line.y2}) slope = ${line.slope} yin = ${line.yIntercept}")
		// }
	}

	fun findParent(child: Int): Int{
		if(parent[child] == child) return child
		parent[child] = findParent(parent[child])
		return parent[child]
	}

	fun union(a: Int, b: Int){
		parent[findParent(a)] = findParent(b)	
	}


	fun solve(){
		for(i in 0 until N){
			for(j in i+1 until N){
				if(findParent(i)!=findParent(j) && list[i].isCross(list[j])){
					union(i, j)
				}
			}
		}
		var ans = IntArray(N)
		for(i in 0 until N){
			ans[findParent(i)]++
		}
		var max = 0
		var count = 0
		for(i in 0 until N){
			if(ans[i]>0) count++
			max = Math.max(max, ans[i])
		}
		println(count)
		println(max)

	}


	input()
	solve()
	
	

}