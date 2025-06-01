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

    val T = br.readLine().toInt()
    repeat(T) {
        val N = br.readLine().toInt()

        var isPalindrome = false

        for (now in 2..64) {
            var copyN = N

            val list = mutableListOf<Int>()

            while(copyN > 0) {
                list.add(copyN % now)
                copyN /= now
            }

            var chk = false
            for (i in 0 until list.size / 2) {
                if (list[i] != list[list.size - 1 - i]) {
                    chk = true
                }
            }

            if (!chk) {
                isPalindrome = true
                break
            }
        }

        if (isPalindrome) {
            bw.write(1.toString())
        }
        else {
            bw.write(0.toString())
        }
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}