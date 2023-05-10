N = int(input())

for i in range(1, N + 1):
    for j in range(i, N):
        print(end=' ')
    for j in range(0, i * 2 - 1):
        print('*', end='')
    print()

for i in range(1, N):
    for j in range(0, i):
        print(end=' ')
    for j in range(0, (N - i) * 2 - 1):
        print('*', end='')

    if i < N - 1:
        print()
