fun main(args: Array<String>){
    var num1 = readLine()!!.toInt()
    for (i in num1 downTo 1) {
        for (j in i + 1 .. num1) {
            print(" ")
        }
        for (j in 1 .. i) {
            print("*")
        }
        print("\n")
    }
}