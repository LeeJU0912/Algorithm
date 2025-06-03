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

    val N = br.readLine().toInt()
    val data = MutableList(N) { Pair(0, 0) }
    val DP = MutableList(N) { MutableList(2) {0} }

    for (i in 0 until N - 1) {
        val st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        data[i] = Pair(a, b)
    }
    val K = br.readLine().toInt()

    if (N == 1) {
        bw.write("0")
    }
    else if (N == 2) {
        bw.write("${data[0].first}")
    }
    else {
        DP[0][1] = Integer.MAX_VALUE / 2
        DP[1][1] = Integer.MAX_VALUE / 2
        DP[2][1] = Integer.MAX_VALUE / 2

        DP[1][0] = data[0].first
        DP[2][0] = min(DP[1][0] + data[1].first, data[0].second)
        for (i in 3 until N) {
            DP[i][0] = min(DP[i - 1][0] + data[i - 1].first, DP[i - 2][0] + data[i - 2].second)
            DP[i][1] = min(min(DP[i - 1][1] + data[i - 1].first, DP[i - 2][1] + data[i - 2].second), DP[i - 3][0] + K)
        }

        bw.write("${min(DP[N-1][0], DP[N-1][1])}")
    }

    bw.flush()
    bw.close()
    br.close()
}