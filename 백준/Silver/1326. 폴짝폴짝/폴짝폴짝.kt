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

    val N = br.readLine().toInt()
    var st = StringTokenizer(br.readLine())

    val array = MutableList(N) { 0 }
    val chk = MutableList(N) { false }
    for (i in 0..N - 1) {
        array[i] = st.nextToken().toInt()
    }
    st = StringTokenizer(br.readLine())
    val start = st.nextToken().toInt()
    val end = st.nextToken().toInt()

    var cnt = 0
    var queue = ArrayDeque<Int>()
    queue.add(start - 1)
    chk[start - 1] = true

    while(queue.isNotEmpty()) {
        if (chk[end - 1]) break
        val nextQueue = ArrayDeque<Int>()

        while(queue.isNotEmpty()) {
            val now = queue.removeFirst()
            val nextMultiplier = array[now]
            var multiply = 1
            while(now - nextMultiplier * multiply >= 0) {
                val next = now - nextMultiplier * multiply++
                if (!chk[next]) {
                    chk[next] = true
                    nextQueue.add(next)
                }
            }
            multiply = 1
            while(now + nextMultiplier * multiply < N) {
                val next = now + nextMultiplier * multiply++
                if (!chk[next]) {
                    chk[next] = true
                    nextQueue.add(next)
                }
            }
        }
        queue = nextQueue
        cnt++
    }
    
    if (chk[end - 1]) {
        bw.write("$cnt")
    }
    else {
        bw.write("-1")
    }

    bw.flush()
    bw.close()
    br.close()
}