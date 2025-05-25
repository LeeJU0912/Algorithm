import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val st = StringTokenizer(br.readLine())
    val s = br.readLine().toInt()

    val list = ArrayList<Int>()

    for (i in 0..<n) {
        list.add(st.nextToken().toInt())
    }

    val DP = BooleanArray(n)
    val queue: Queue<Int> = LinkedList()
    queue.add(s - 1)
    DP[s - 1] = true
    var ans = 1

    while(!queue.isEmpty()) {
        val now = queue.poll()

        val next1 = now - list[now]
        if (next1 >= 0 && !DP[next1]) {
            DP[next1] = true
            queue.add(next1)
            ans++
        }

        val next2 = now + list[now]
        if (next2 < n && !DP[next2]) {
            DP[next2] = true
            queue.add(next2)
            ans++
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}