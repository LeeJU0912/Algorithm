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

    var st = StringTokenizer(br.readLine())

    val N: Int = st.nextToken().toInt()
    val M: Int = st.nextToken().toInt()

    val board = Array(N) { IntArray(M) }

    for (i in 0..N - 1) {
        st = StringTokenizer(br.readLine())

        for (j in 0..M - 1) {
            board[i][j] = st.nextToken().toInt()
        }
    }

    val dx = arrayOf(1, 0)
    val dy = arrayOf(0, 1)

    val cnt = Array(N) { IntArray(M) { -1 } }

    val q: Queue<Pair<Int, Int>> = LinkedList()

    q.add(Pair(0, 0))
    cnt[0][0] = board[0][0]

    while(!q.isEmpty()) {
        val nowX = q.peek().first
        val nowY = q.peek().second
        q.poll()

        for (i in 0..1) {
            val nextX = nowX + dx[i]
            val nextY = nowY + dy[i]

            if (nextX >= N || nextY >= M) continue
            if (cnt[nextX][nextY] >= cnt[nowX][nowY] + board[nextX][nextY]) continue
            cnt[nextX][nextY] = cnt[nowX][nowY] + board[nextX][nextY]

            q.add(Pair(nextX, nextY))
        }
    }

    bw.write("${cnt[N - 1][M - 1]}")

    bw.flush()
    bw.close()
    br.close()
}