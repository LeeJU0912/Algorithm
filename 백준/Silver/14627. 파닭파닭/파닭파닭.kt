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

    val st = StringTokenizer(br.readLine())
    val S = st.nextToken().toInt()
    val C = st.nextToken().toInt()

    val list = MutableList(S) { 0L }

    var start = 1L
    var end = 1_000_000_000L

    var hap = 0L
    for (i in 0 until S) {
        val L = br.readLine().toLong()

        list[i] = L
        hap += L
    }

    var ans = 0L
    while(start <= end) {
        val mid = (start + end) / 2

        var cnt = 0L

        for (i in list) {
            cnt += i / mid
        }

        if (cnt < C) {
            end = mid - 1
        }
        else {
            ans = (hap - mid * C)
            start = mid + 1
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}