a = int(input())

x = list()
y = list()
z = list()

for i in range(a):
    b, c, d = map(int,input().split())
    x.append(b)
    y.append(c)
    z.append(d)

for i in range(a):
    e = int(z[i] / x[i] + 1) #호수
    f = int(z[i] % x[i]) #층수
    if f == 0:
        print(x[i] * 100 + e - 1)
    else:
        print(f * 100 + e)