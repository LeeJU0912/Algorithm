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

    val st = StringTokenizer(br.readLine())

    val N: Int = st.nextToken().toInt()
    val K: Int = st.nextToken().toInt()

    val list: MutableList<Int> = ArrayList()

    for (i in 0..N - 1) {
        val x = br.readLine().toInt()
        list.add(x)
    }

    var start = 0L
    var end = Int.MAX_VALUE.toLong()
    var ans = 0L

    while(start <= end) {
        val mid = (start + end) / 2

        var hap = 0L

        for (i in list) {
            hap += i / mid
        }

        if (hap >= K) {
            ans = mid
            start = mid + 1
        }
        else {
            end = mid - 1
        }
    }

    bw.write("$ans")

    bw.flush()
    bw.close()
    br.close()
}