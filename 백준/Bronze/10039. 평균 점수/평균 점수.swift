import Foundation

var a: Int
var b: Int
var c: Int
var d: Int
var e: Int
var ans: Int

a = Int(readLine()!)!
if (a < 40) {
    a = 40
}
b = Int(readLine()!)!
if (b < 40) {
    b = 40
}
c = Int(readLine()!)!
if (c < 40) {
    c = 40
}
d = Int(readLine()!)!
if (d < 40) {
    d = 40
}
e = Int(readLine()!)!
if (e < 40) {
    e = 40
}

ans = (a + b + c + d + e) / 5

print(ans)