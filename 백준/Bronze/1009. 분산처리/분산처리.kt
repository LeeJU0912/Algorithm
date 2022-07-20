import java.util.*

fun main() {
    var input = Scanner(System.`in`)

    var X = input.nextInt()

    for(i: Int in 1 .. X) {
        var a = input.nextInt()
        var b = input.nextInt()
        var c = 1
        for(j: Int in 1..b) {
            c *= a
            if (c > 10) {
                c %= 10
                if (c == 0) {
                    c = 10
                }
            }
        }
        println(c)
    }
}