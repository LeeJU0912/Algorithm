a = int(input())
b = []
c = []
d = []
e = []

for i in range(a):
    b.append([])
    b[i] = list(map(int,input().split()))

for i in range(a):
    hap = 0
    for g in range(b[i][0]):
        hap = hap + b[i][g + 1]

    average = hap / b[i][0]
    d.append(hap)
    c.append(average)

for i in range(a):
    good = 0
    for g in range(b[i][0]):
        if b[i][g + 1] > c[i]:
            good += 1
    e.append(good)

for i in range(a):
    f = "{:.3f}".format((e[i] / b[i][0]) * 100)
    print(f, "%", sep='')