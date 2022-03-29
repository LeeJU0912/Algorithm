y = int(input())
x = 1
k = 1
n = 0

while y != x + n:
    if y == 2:
        x = 1
        break
    elif y < x:
        x = 0
        break
    elif y == x + n:
        break

    x += 1
    k = x
    n = 0
    while k >= 1:
        t = k % 10
        k = k // 10
        n += t

if y == 1:
    x = 0

print(x)