a = int(input())

x = list()
y = list()


for i in range(a):
    b = int(input())
    c = int(input())
    x.append(b)
    y.append(c)


for i in range(a):
    z = list()
    for n in range(y[i]):
        
        z.append(n + 1)

    if x[i] >= 1:
        for m in range(x[i]):
            w = 0
            for e in range(y[i]):
                j = e + m * y[i]
                w = w + z[j]
                z.append(w)


    print(w)
    