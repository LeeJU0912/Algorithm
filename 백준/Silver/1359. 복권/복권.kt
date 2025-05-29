import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())

    val N = st.nextToken().toInt()
    val M = st.nextToken().toInt()
    val K = st.nextToken().toInt()

    if (2 * M - N >= K) {
        bw.write("1.0")
        bw.flush()
        bw.close()
        br.close()
        return
    }

    var maxi = 1.0
    for (i in N - M + 1..N) {
        maxi *= i
    }
    for (i in 1..M) {
        maxi /= i
    }

    var up = 0.0
    for (i in K..M) {
        val others = N - M
        val left = M - i

        var one = 1.0
        var two = 1.0

        for (j in others - left + 1..others) {
            one *= j
        }
        for (j in 1..left) {
            one /= j
        }
        for (j in M - i + 1..M) {
            two *= j
        }
        for (j in 1..i) {
            two /= j
        }

        up += one * two
    }

    bw.write("${up/maxi}")

    bw.flush()
    bw.close()
    br.close()
}