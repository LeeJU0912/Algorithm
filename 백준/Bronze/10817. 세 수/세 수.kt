import java.util.*

fun main() {
    var input = Scanner(System.`in`)
    var list = mutableListOf<Int>()

    for(i: Int in 0..2) {
        list.add(input.nextInt())
    }
    var sorted = list.sorted()

    print(sorted[1])
}