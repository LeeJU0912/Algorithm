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

    val N = br.readLine().toInt()

    val list = MutableList(N) { 0.0 }

    val st = StringTokenizer(br.readLine())
    for (i in 0 until N) {
        list[i] = st.nextToken().toDouble()
    }

    list.sort()

    for (i in 0 until N - 1) {
        list[N - 1] += list[i] / 2
    }

    bw.write("${list[N - 1]}")

    bw.flush()
    bw.close()
    br.close()
}