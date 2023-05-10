save = []

for i in range(0, 9):
    save.append([])
    x = list(map(int, input().split()))
    for j in range(0, 9):
        save[i].append(x[j])


maxi = 0
idx_x = 0
idx_y = 0
for i in range(0, 9):
    for j in range(0, 9):
        if save[i][j] > maxi:
            maxi = save[i][j]
            idx_x = i
            idx_y = j


print(maxi)
print(idx_x + 1, end=' ')
print(idx_y + 1)
