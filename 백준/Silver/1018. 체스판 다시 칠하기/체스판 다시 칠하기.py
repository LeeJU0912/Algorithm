c = 0
d = 0
save = 1000
save2 = 1000
a, b = map(int, input().split())

chess = [[0 for col in range(b)] for row in range(a)]

for i in range(a):
    chess[i] = input()

while (1):

    if d + 7 == b:
        c += 1
        if c + 7 == a and d + 7 == b:
            break
        d = 0
    counter = 0
    counter2 = 0
    for i in range(4):
        for g in range(4):
            if chess[c + 2 * i][d + 2 * g] != 'W':
                counter += 1
            if chess[c + 2 * i][d + 2 * g + 1] != 'B':
                counter += 1
            if chess[c + 2 * i][d + 2 * g] != 'B':
                counter2 += 1
            if chess[c + 2 * i][d + 2 * g + 1] != 'W':
                counter2 += 1
            if chess[c + 2 * i + 1][d + 2 * g] != 'B':
                counter += 1
            if chess[c + 2 * i + 1][d + 2 * g + 1] != 'W':
                counter += 1
            if chess[c + 2 * i + 1][d + 2 * g] != 'W':
                counter2 += 1
            if chess[c + 2 * i + 1][d + 2 * g + 1] != 'B':
                counter2 += 1

    if save > counter:
        save = counter
    if save2 > counter2:
        save2 = counter2


    d += 1


if save <= save2:
    print(save)
elif save2 < save:
    print(save2)