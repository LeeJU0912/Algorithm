import Foundation


let input = readLine()!.split(separator:" ").map { Int(String($0))! }

var answer = [Int](repeating: 0, count: 6)

answer[0] = 1 - input[0]
answer[1] = 1 - input[1]
answer[2] = 2 - input[2]
answer[3] = 2 - input[3]
answer[4] = 2 - input[4]
answer[5] = 8 - input[5]

for i in 0...5 {
    print(answer[i])
}
