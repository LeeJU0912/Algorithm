import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val R = st.nextToken().toInt()
    val C = st.nextToken().toInt()
    val W = st.nextToken().toInt()

    val map = Array(R + W + 1) { IntArray(R + W + 1) }

    map[0][0] = 1

    for (i in 1..R + W) {
        for (j in 1..i) {
            map[i][j] = map[i - 1][j - 1] + map[i - 1][j]
        }
    }

    var ans = 0
    for (i in R until R + W) {
        for (j in 0..i - R) {
            ans += map[i][C + j]
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}