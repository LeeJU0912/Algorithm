x = list()
y = list()
z = list()
d = list()
e = list()
f = list()

g = 0

while True:
    a, b, c = map(int,input().split())
    x.append(a)
    y.append(b)
    z.append(c)
    g = g + 1

    if a == 0 and b == 0 and c == 0:
        g = g - 1
        break

for i in range(g):
    h = (x[i] * x[i]) + (y[i] * y[i]) - (z[i] * z[i])
    k = (y[i] * y[i]) + (z[i] * z[i]) - (x[i] * x[i])
    j = (x[i] * x[i]) + (z[i] * z[i]) - (y[i] * y[i])

    d.append(h)
    e.append(k)
    f.append(j)


for i in range(g):
    if d[i] == 0 or e[i] == 0 or f[i] == 0:
        print("right")
    else:
        print("wrong")
