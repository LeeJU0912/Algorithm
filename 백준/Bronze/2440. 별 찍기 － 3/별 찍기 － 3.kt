import java.util.*

fun main() {
    var input = Scanner(System.`in`)

    var X = input.nextInt()

    for(i: Int in X downTo 1) {
        for(j: Int in 1..i) {
            print("*")
        }
        print("\n")
    }

}