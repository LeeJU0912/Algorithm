import Foundation

var total = 0

for _ in 1...5 {
    let temp = Int(readLine()!)!
    
    total += temp
}

print(total)