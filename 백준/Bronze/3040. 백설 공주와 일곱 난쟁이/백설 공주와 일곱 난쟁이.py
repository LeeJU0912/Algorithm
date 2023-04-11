save = []


for i in range(9):
    N = int(input())
    save.append(N)

hap = sum(save)

for i in range(8):
    for j in range(i + 1, 9):
        if hap - save[i] - save[j] == 100:
            a, b = i, j

save.pop(a)
save.pop(b - 1)

for i in save:
    print(i)