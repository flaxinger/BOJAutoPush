/*
	kotlinc main.kt -include-runtime -d main.jar && java -Xmx1024M -Xms256M -jar main.jar
*/

fun main(){
	
	var N = 0
	var list = mutableListOf<String>()

	fun input(){
		N = readln().toInt()
	 	list = readln().split(" ").toMutableList()
	}

	fun comp(a: String, b: String): Int{
		var i = 0
		var j = 0
		repeat(Math.max(a.length, b.length)){
			if(a[i]!=b[j]){
				return b[j].compareTo(a[i])
			}
			i++
			j++
			if(i == a.length)
				i = 0
			if(j == b.length)
				j = 0
			// i = Math.min(a.length-1, i+1)
			// j = Math.min(b.length-1, j+1)
		}
		return b[j].compareTo(a[i])
	}

	fun solve(){
		list.sortWith(Comparator{
			a: String, b: String -> comp(a, b)
		})
		if(list[0] == "0"){
			println(0)
		}
		else {
			for(a in list)
				print(a)
		}
	}

	input()
	solve()

}