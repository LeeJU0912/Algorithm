from collections import deque

save = []

for i in range(9):
    N = int(input())
    save.append(N)

ans = 0

temp = deque()


def solve(idx, counter, hap):
    if idx >= 9:
        return

    if counter == 7:
        if hap == 100:
            while len(temp) != 0:
                print(temp.popleft())
            exit()

    for j in range(idx + 1, 9):
        temp.append(save[j])
        solve(j, counter + 1, hap + save[j])
        temp.pop()


for i in range(3):
    temp.append(save[i])
    solve(i, 1, save[i])
    temp.pop()
