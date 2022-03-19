a, b = map(int,input().split())

c = 1
d = 1
e = 1

for i in range(a):
    c = c * (i + 1)

for i in range(b):
    d = d * (i + 1)

for i in range(a - b):
    e = e * (i + 1)

f = int(c / (d * e))

print(f)