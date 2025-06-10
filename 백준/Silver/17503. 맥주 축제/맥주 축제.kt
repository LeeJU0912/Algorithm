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

    var st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val M = st.nextToken().toInt()
    val K = st.nextToken().toInt()

    val beer = MutableList(K) { Pair(0, 0) }
    for (i in 0 until K) {
        st = StringTokenizer(br.readLine())
        val v = st.nextToken().toInt()
        val c = st.nextToken().toInt()

        beer[i] = Pair(v, c)
    }

    beer.sortWith(Comparator { o1, o2 -> o2.first - o1.first })

    var start = 1L
    var end = Int.MAX_VALUE.toLong()
    var ans = -1L

    while (start <= end) {
        val mid = (start + end) / 2

        var count = 0
        var favorite = 0
        for (i in beer) {
            if (i.second <= mid) {
                favorite += i.first
                count++
            }

            if (count == N) break
        }
        
        if (count < N) favorite = 0

        if (favorite >= M) {
            ans = mid
            end = mid - 1
        }
        else {
            start = mid + 1
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}