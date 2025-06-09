import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.max
import kotlin.math.min
import kotlin.math.pow

var N = 0
var ans = 0

fun solve(cnt:Int, now:Int, last:Int) {
    if (cnt == N) {
        if (last != 0 && now % 3 == 0) ans++
        return
    }

    for (i in 0..2) {
        solve(cnt + 1, now + i, i)
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    N = br.readLine().toInt()

    solve(0, 0, 0)

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}