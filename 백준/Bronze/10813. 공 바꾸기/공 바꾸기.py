N, M = map(int, input().split())

save = []

for i in range(1, N + 1):
    save.append(i)

for i in range(0, M):
    a, b = map(int, input().split())

    temp = save[a - 1]
    save[a - 1] = save[b - 1]
    save[b - 1] = temp

for i in range(0, N):
    print(save[i], end=' ')