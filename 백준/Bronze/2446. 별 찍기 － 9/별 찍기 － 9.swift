import Foundation

var n = Int(readLine()!)!

for i in 1...n {
    for _ in 1..<i {
        print(" ", terminator: "")
    }
    for _ in 1...(2 * (n - i) + 1) {
        print("*", terminator: "")
    }
    print()
}
if n > 1 {
    for i in 2...n {
        for _ in 1..<(n - i + 1) {
            print(" ", terminator: "")
        }
        for _ in 1...(i * 2 - 1) {
            print("*", terminator: "")
        }
        print()
    }
}
