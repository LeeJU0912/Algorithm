a, b = map(int, input().split())

c = int(a * 60 + b)

d = int(c % 60)

e = int(c / 60)

f = int((c - 45) % 60)

g = int((c - 45) / 60)

if c < 45:
    e = 23
    print(e, f)
else:
    print(g, f)