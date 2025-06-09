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

    val dx = listOf(0, 0, 1, -1)
    val dy = listOf(1, -1, 0, 0)

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val board = MutableList(n) { MutableList(m) { 0 } }
    val visited = MutableList(n) { MutableList(m) { false } }

    var startX = 0
    var startY = 0
    for (i in 0 until n) {
        val s = br.readLine().toCharArray()
        for (j in 0 until m) {
            board[i][j] = s[j] - '0'

            if (board[i][j] == 2) {
                startX = i
                startY = j
            }
        }
    }

    val queue = ArrayDeque<Pair<Pair<Int, Int>, Int>>()
    queue.add(Pair(Pair(startX, startY), 0))
    visited[startX][startY] = true

    var ans = -1
    while (queue.isNotEmpty()) {
        val (nowX, nowY) = queue.first().first
        val nowCnt = queue.removeFirst().second

        if (board[nowX][nowY] > 2) {
            ans = nowCnt
            break
        }

        for (i in 0 until 4) {
            val nextX = nowX + dx[i]
            val nextY = nowY + dy[i]

            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m) continue
            if (board[nextX][nextY] == 1) continue
            if (visited[nextX][nextY]) continue
            visited[nextX][nextY] = true

            queue.add(Pair(Pair(nextX, nextY), nowCnt + 1))
        }
    }

    if (ans == -1) {
        bw.write("NIE")
    }
    else {
        bw.write("TAK\n${ans}")
    }

    bw.flush()
    bw.close()
    br.close()
}