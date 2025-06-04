import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.min
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val N = st.nextToken().toInt()
    val Q = st.nextToken().toInt()

    val set = HashSet<Int>()

    for (i in 0 until Q) {
        var x = br.readLine().toInt()
        val origin = x

        var canGo = true
        var firstContact = 0
        while(x >= 1) {
            if (set.contains(x)) {
                canGo = false
                firstContact = x
            }

            x = x / 2
        }

        if (canGo) {
            bw.write("0")
            set.add(origin)
        }
        else {
            bw.write(firstContact.toString())
        }
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}