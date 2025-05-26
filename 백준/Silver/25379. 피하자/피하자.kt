import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer
import kotlin.math.min

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val A: List<Int> = br.readLine().split(" ").map { it.toInt() }

    var target = 0

    var ans1 = 0
    var ans2 = 0
    for (i in 0 until N) {
        if (A[i] % 2 == 0) {
            ans1 += (i - target++)
        }
    }

    target = 0
    for (i in 0 until N) {
        if (A[i] % 2 == 1) {
            ans2 += (i - target++)
        }
    }

    bw.write("${min(ans1, ans2)}")

    bw.flush()
    bw.close()
    br.close()
}