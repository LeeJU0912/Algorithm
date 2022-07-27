import Foundation

var n = Int(readLine()!)!

for i in (1...n).reversed() {
    for k in 0 ..< n - i {
        print(" ", terminator: "")
    }
    for j in 1 ... 2 * i - 1 {
        print("*", terminator: "")
    }
    print("")
}
