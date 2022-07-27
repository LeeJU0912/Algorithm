import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))

    var total = 0
    var maxi = 0

    for (i in 1..4) {
        val (n , m) = br.readLine().split(' ').map { it.toInt() }
        total += m - n
        if (maxi < total) {
            maxi = total
        }
    }
    print(maxi)
}