import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.PriorityQueue
import java.util.StringTokenizer
import kotlin.math.min
import kotlin.math.pow

val primes = mutableListOf<Int>()

val temp = mutableListOf<Int>()
val ans = mutableListOf<Int>()

fun solve(left:Int, idx:Int) {
    if (ans.isNotEmpty()) return
    if (left < 0) return
    if (temp.size > 3) return
    if (left == 0 && temp.size == 3) {
        for (t in temp) ans.add(t)
        return
    }

    for (i in idx until primes.size) {
        temp.add(primes[i])
        solve(left - primes[i], i)
        temp.removeAt(temp.lastIndex)
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val isPrime = BooleanArray(1001) { true }

    isPrime[0] = false
    isPrime[1] = false
    for (i in 2..1000) {
        if (!isPrime[i]) continue
        for (j in 2..1000 / i) {
            if (i * j > 1000) break
            isPrime[i * j] = false
        }
    }

    for (i in 2..1000) {
        if (isPrime[i]) primes.add(i)
    }

    val T = br.readLine().toInt()
    repeat(T) {
        ans.clear()
        temp.clear()
        val K = br.readLine().toInt()

        solve(K, 0)

        if (ans.isEmpty()) bw.write("0")
        else {
            for (i in ans) bw.write(
                "$i "
            )
        }
        bw.newLine()
    }

    bw.flush()
    bw.close()
    br.close()
}