import java.util.Scanner

fun main() {
	val scan = Scanner(System.`in`)
	var n = scan.nextInt()
	var w = scan.nextLong();
	var mn: Long = 0
	var mx: Long = w
	var sm: Long = 0;
	var x: Long = 12;
	for(i in 1..n) {
		var t = scan.nextInt()
		sm = sm.plus(t)
		if(sm.times(-1).compareTo(mn) > 0) mn = sm.times(-1)
		if(w.minus(sm).compareTo(mx) < 0) mx = w - sm
	}
	println((mx - mn + 1).let {
		if(it < 0) 
			0
		else it
	})
}
