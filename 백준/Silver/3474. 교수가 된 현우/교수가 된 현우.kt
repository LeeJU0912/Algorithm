import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.min
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()
    for (t in 0 until T) {
        val N = br.readLine().toInt()

        var ans = 0
        var multi = 5
        while(multi <= N) {
            ans += N / multi
            multi *= 5
        }

        bw.write("$ans")
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}