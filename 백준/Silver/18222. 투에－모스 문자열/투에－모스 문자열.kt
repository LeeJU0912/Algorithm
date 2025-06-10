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

    var k = br.readLine().toLong()

    var ans = 0

    k--
    while(k > 0){
        if (k and 1 == 1L) {
            ans = ans xor 1
        }

        k = k shr 1
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}