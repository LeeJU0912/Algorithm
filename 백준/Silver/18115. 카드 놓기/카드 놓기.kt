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
    val A = MutableList(N) { 0 }

    val st = StringTokenizer(br.readLine())
    for (i in 0 until N) {
        A[i] = st.nextToken().toInt()
    }

    val dq = ArrayDeque<Int>()
    var cnt = 1

    for (i in N - 1 downTo 0) {
        if (A[i] == 1) {
            dq.addFirst(cnt)
        }
        else if (A[i] == 2) {
            val nowFirst = dq.removeFirst()
            dq.addFirst(cnt)
            dq.addFirst(nowFirst)
        }
        else if (A[i] == 3) {
            dq.addLast(cnt)
        }
        cnt++
    }

    while(!dq.isEmpty()) {
        bw.write("${dq.removeFirst()} ")
    }

    bw.flush()
    bw.close()
    br.close()
}