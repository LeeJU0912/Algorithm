import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val s = br.readLine()!!

    val level = MutableList(50) {0}
    var temp = 0
    var nowLevel = 0

    for (c in s) {
        if (c == '(') {
            if (temp != 0) {
                level[nowLevel] += temp
                temp = 0
            }
            nowLevel++
        }
        else if (c == ')') {
            if (temp != 0) {
                level[nowLevel] += temp
            }
            temp = level[nowLevel]
            level[nowLevel] = 0
            nowLevel--
        }
        else if (c >= '0' && c <= '9') {
            if (temp != 0) {
                level[nowLevel] += temp * (c - '0')
                temp = 0
            }
        }
        else if (c == 'H') {
            if (temp != 0) {
                level[nowLevel] += temp
                temp = 0
            }
            temp += 1
        }
        else if (c == 'C') {
            if (temp != 0) {
                level[nowLevel] += temp
                temp = 0
            }
            temp += 12
        }
        else if (c == 'O') {
            if (temp != 0) {
                level[nowLevel] += temp
                temp = 0
            }
            temp += 16
        }
    }

    bw.write("${level[0] + temp}")

    bw.flush()
    bw.close()
    br.close()
}