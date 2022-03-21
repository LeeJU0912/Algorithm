a = int(input())
b = list()
c = list()
d = list()

for i in range(a):
    e, f = map(str,input().split())
    b.append(int(e))
    c.append(list(f))
    d.append(len(c[i]))

for i in range(a):
    for g in range(d[i]):
        for j in range(b[i]):
            print(c[i][g], end='')
    print()
