fun main(args: Array<String>){
    var n:Int = readLine()!!.toInt()

    for (a in 1..n) {
        for (i in n - 1 downTo a) {
            print(" ")
        }

        for (i in 0 until (2 * a - 1)) {
            print("*")
        }
        print("\n")
    }
}