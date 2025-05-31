import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var st = StringTokenizer(br.readLine())
    val a = st.nextToken().toInt()
    val b = st.nextToken().toInt()
    st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val M = st.nextToken().toInt()

    val graph = Array(N + 1) { mutableListOf<Int>() }
    val cost = IntArray(N + 1) { Int.MAX_VALUE }

    for (i in 0 until M) {
        st = StringTokenizer(br.readLine())
        val x = st.nextToken().toInt()
        val y = st.nextToken().toInt()

        graph[x].add(y)
        graph[y].add(x)
    }

    val queue = ArrayDeque<Int>()
    queue.add(a)
    cost[a] = 0
    
    while(!queue.isEmpty()) {
        val now = queue.removeFirst()

        if (now == b) {
            continue
        }

        for (next in graph[now]) {
            if (cost[now] + 1 >= cost[next]) continue
            cost[next] = cost[now] + 1
            queue.add(next)
        }
    }

    if (cost[b] == Int.MAX_VALUE) {
        bw.write("-1")
    }
    else bw.write("${cost[b]}")

    bw.flush()
    bw.close()
    br.close()
}