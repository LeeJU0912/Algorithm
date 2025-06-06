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
    val M = st.nextToken().toInt()

    val board = MutableList(N) { MutableList(M) { 0 } }

    for (i in 0 until N) {
        st = StringTokenizer(br.readLine())
        for (j in 0 until M) {
            board[i][j] = st.nextToken().toInt()
        }
    }

    val DP = MutableList(N) { MutableList(M) { MutableList(3) { Int.MAX_VALUE } } }

    for (i in 0 until M) {
        for (j in 0 until 3) {
            DP[0][i][j] = board[0][i]
        }
    }

    for (i in 1 until N) {
        for (j in 0 until M) {
            if (j == 0) {
                DP[i][j][1] = board[i][j] + min(DP[i - 1][0][0], DP[i - 1][0][2])
                DP[i][j][2] = board[i][j] + min(DP[i - 1][1][0], DP[i - 1][1][1])
            }
            else if (j == M - 1) {
                DP[i][j][0] = board[i][j] + min(DP[i - 1][M - 2][1], DP[i - 1][M - 2][2])
                DP[i][j][1] = board[i][j] + min(DP[i - 1][M - 1][0], DP[i - 1][M - 1][2])
            }
            else {
                DP[i][j][0] = board[i][j] + min(DP[i - 1][j - 1][1], DP[i - 1][j - 1][2])
                DP[i][j][1] = board[i][j] + min(DP[i - 1][j][0], DP[i - 1][j][2])
                DP[i][j][2] = board[i][j] + min(DP[i - 1][j + 1][0], DP[i - 1][j + 1][1])
            }
        }
    }

    var ans = Int.MAX_VALUE
    for (i in 0 until M) {
        for (j in 0 until 3) {
            ans = min(ans, DP[N - 1][i][j])
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}