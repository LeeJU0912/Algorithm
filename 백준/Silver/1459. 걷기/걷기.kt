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

    val X = st.nextToken().toLong()
    val Y = st.nextToken().toLong()
    val W = st.nextToken().toInt()
    val S = st.nextToken().toInt()

    if (W * 2 <= S) {
        bw.write("${(X + Y) * W}")
    }
    else {
        val maxi = max(X, Y)
        val mini = min(X, Y)
        val left = (maxi - mini)

        if (left % 2 == 1L) {
            if (mini > 0) {
                if (S < W) {
                    bw.write("${mini * S + (left - 1) * S + W}")
                }
                else {
                    bw.write("${mini * S + left * W}")
                }
            }
            else {
                if (S < W) {
                    val left2 = maxi % 2

                    if (left2 == 1L) {
                        bw.write("${(maxi - 1) * S + left2 * W}")
                    }
                    else {
                        bw.write("${maxi * S}")
                    }
                }
                else {
                    bw.write("${maxi * W}")
                }
            }
        }
        else {
            bw.write("${mini * S + left * min(S, W)}")
        }
    }

    bw.flush()
    bw.close()
    br.close()
}