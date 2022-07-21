import Foundation

var a: Int
var b: Int

a = 1
b = 1

while (true) {
    let input = readLine()!.split(separator: " ").map { Int(String($0))!}
    a = input[0]
    b = input[1]
    
    if (a == 0 && b == 0) {
        break
    }
    if (a > b) {
        print("Yes")
    }
    else {
        print("No")
    }
}