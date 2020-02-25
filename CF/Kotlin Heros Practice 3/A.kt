import java.util.Scanner

fun get(a: Int, b: Int, c: Int, d: Int): List<Int> {
	var list = mutableListOf(a, b, c, d);
	list.sort()
	list.remove(list[list.size - 1])
	return list
}

fun main() {
	val scanner:Scanner = Scanner(System.`in`)
	var a: Int = scanner.nextInt()
	var b = scanner.nextInt()
	var c = scanner.nextInt()
	var d = scanner.nextInt()
	var nec: List<Int> = get(a, b, c, d)
	var x = (nec[2] + (nec[0] - nec[1])) / 2
	var y = nec[0] - x
	var z = nec[2] - x
	println("$x $y $z")
}
