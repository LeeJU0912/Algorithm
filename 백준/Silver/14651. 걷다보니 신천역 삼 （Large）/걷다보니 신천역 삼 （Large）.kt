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

    val MOD = 1_000_000_009

    val N = br.readLine().toInt()

    if (N == 1) {
        bw.write("0")
    }
    else {
        val DP = MutableList(N + 1) { MutableList(3) { 0 } }

        DP[2][0] = 2
        DP[2][1] = 2
        DP[2][2] = 2

        for (i in 3..N) {
            DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % MOD + DP[i - 1][2]
            DP[i][1] = (DP[i - 1][0] + DP[i - 1][1]) % MOD + DP[i - 1][2]
            DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % MOD + DP[i - 1][2]
            
            for (j in 0 until 3) {
                DP[i][j] %= MOD
            }
        }

        bw.write("${DP[N][0]}")
    }

    bw.flush()
    bw.close()
    br.close()
}