import java.util.Scanner

fun main() {
	val scan = Scanner(System.`in`)
	var n: Int = scan.nextInt()
	var list = mutableListOf<Int>()
	for(i in 1..n) {
		list.add(scan.nextInt())
	}
	var mp = mutableMapOf<Int, Int>()
	var ind: Int = 0
	for(x in list) {
		mp[x] = ind
		ind++;
	}
	ind = 0
	println(mp.size)
	for(x in list) {
		if(ind == mp.getValue(x))
			print(x.toString() + " ");
		ind++;
	}
}
