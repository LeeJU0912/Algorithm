import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.max
import kotlin.math.min
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var K = br.readLine().toInt()

    if (K == 1) {
        bw.write("1 0")
    }
    else {
        var ans1 = 1
        while(ans1 < K) {
            ans1 = ans1 shl 1
        }

        if (ans1 == K) {
            bw.write("$ans1 0")
        }
        else {
            var counter = 0
            var copy = ans1

            var ans2 = 0
            while(copy > 0) {
                if (copy and K == copy) {
                    ans2 = counter
                }

                counter++

                copy = copy shr 1
            }

            bw.write("$ans1 $ans2")
        }
    }


    bw.flush()
    bw.close()
    br.close()
}