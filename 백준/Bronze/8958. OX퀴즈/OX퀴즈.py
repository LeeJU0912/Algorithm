a = int(input())

d = list()

c = [list(input()) for t in range(a)]

for i in range(a):
    xstreak = 0
    streak = 0
    for g in range(len(c[i])):
        if c[i][g] == 'O':
            xstreak = xstreak + 1
            streak = streak + xstreak
            

        else:
            xstreak = 0

    d.append(streak)

for j in range(a):
    print(d[j])