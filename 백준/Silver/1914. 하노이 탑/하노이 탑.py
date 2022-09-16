def hanoi(n, start, to, temp):
    if n == 1:
        print(start, to)
    else:
        hanoi(n - 1, start, temp, to)
        print(start, to)
        hanoi(n - 1, temp, to, start)


N = int(input())

print((1 << N) - 1)

if N <= 20:
    hanoi(N, 1, 3, 2)