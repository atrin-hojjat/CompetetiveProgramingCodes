import java.util.Scanner

data class Ans(var v: Int) 

fun add(x : Ans, sz: Int) {
	if(sz > 2) x.v += sz - 2
}

fun main() {
	val scan = Scanner(System.`in`)
	val n = scan.nextInt()
	val str: String = scan.next();
	var sz: Int = 0
	var ans: Ans = Ans(0)
	for(t in str) {
		sz = when(t) {
			'x' -> sz + 1
			else -> {
				add(ans, sz)
				0
			}
		}
	}
	add(ans, sz)
	println(ans.v)
}
