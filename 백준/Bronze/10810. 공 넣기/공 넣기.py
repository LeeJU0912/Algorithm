N, M = map(int, input().split())
save = [0 for i in range(1, N + 2)]

for i in range(M):
    a, b, c = map(int, input().split())

    for j in range(a, b + 1):
        save[j] = c

for i in range(1, N + 1):
    print(save[i], end=' ')