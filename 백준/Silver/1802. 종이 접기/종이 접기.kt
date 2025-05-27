import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer
import kotlin.math.min

var ans = false

fun solve(from: Int, to: Int, s: String) {
    if (from == to) return

    var l = from
    var r = to
    while (l < r) {
        if (s[l] == s[r]) {
            ans = true
            return
        }
        l++
        r--
    }

    solve(from, (from + to) / 2 - 1, s)
    solve((from + to) / 2 + 1, to, s)
}

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val T = br.readLine().toInt()
    for (t in 0 until T) {
        val s = br.readLine()
        ans = false

        if (s.length == 1) {
            bw.write("YES")
            bw.newLine()
            continue
        }

        solve(0, s.length - 1, s)

        if (ans) {
            bw.write("NO")
        }
        else {
            bw.write("YES")
        }
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}