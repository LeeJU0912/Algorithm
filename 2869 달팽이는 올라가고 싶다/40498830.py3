a, b, v = map(int,input().split())

n = 1

c = int((v - a) % (a - b))

d = int((v - a) / (a - b))


if c == 0:
    print(d + 1)
else:
    print(d + 2)