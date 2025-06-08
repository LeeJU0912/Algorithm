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

    var st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val K = st.nextToken().toInt()

    var minus = 0
    for (i in 1..K - 1) {
        minus += i
    }

    val list = MutableList(N) { 0 }
    st = StringTokenizer(br.readLine())
    for (i in 0 until N) {
        list[i] = st.nextToken().toInt()
    }

    list.sortWith(Comparator.reverseOrder())

    var plus = 0
    for (i in 0 until K) {
        plus += list[i]
    }

    bw.write("${plus - minus}")

    bw.flush()
    bw.close()
    br.close()
}