import math

T = int(input())

while T != 0:
    T -= 1
    save = list(map(int, input().split()))

    ans = 0
    for i in range(0, len(save) - 1):
        for j in range(i + 1, len(save)):
            ans = max(ans, math.gcd(save[i], save[j]))

    print(ans)