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

    val MOD = 1_000_000_009L

    val DP = MutableList(100001) { 0L }
    DP[1] = 1
    DP[2] = 2
    DP[3] = 2
    DP[4] = 3
    DP[5] = 3
    DP[6] = 6
    for (i in 7..100000) {
        DP[i] = (DP[i - 2] + DP[i - 4] + DP[i - 6]) % MOD
    }

    val T = br.readLine().toInt()
    repeat(T) {
        val n = br.readLine().toInt()
        bw.write("${DP[n]}\n")
    }

    bw.flush()
    bw.close()
    br.close()
}