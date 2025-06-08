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

    val T = br.readLine().toInt()
    repeat(T) {
        val N = br.readLine().toInt()
        val list = MutableList(N) { 'a' }

        val st = StringTokenizer(br.readLine())
        for (i in 0 until N) {
            list[i] = st.nextToken().toCharArray().first()
        }

        val deque = ArrayDeque<Char>()
        deque.addLast(list[0])

        for (i in 1 until N) {
            if (list[i] <= deque.first()) {
                deque.addFirst(list[i])
            }
            else {
                deque.addLast(list[i])
            }
        }

        while(deque.isNotEmpty()) {
            bw.write(deque.removeFirst().toString())
        }
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}