a, b = map(int,input().split())

c = list(map(int,input().split()))

d = list()

for x in range(a):
    if c[x] < b:
        d.append(c[x])

e = len(d)

for y in range(e):
    print(d[y], end=' ')
