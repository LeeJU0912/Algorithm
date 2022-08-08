import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))

    var total = 0
    var low = 100

    for(i in 1..7) {
        val temp = readLine()!!.toInt()
        if (temp % 2 == 1) {
            total += temp
            if (temp < low) {
                low = temp
            }
        }
    }

    if (total == 0) {
        print("-1")
        return;
    }
    else {
        println(total)
    }
    print(low)
}