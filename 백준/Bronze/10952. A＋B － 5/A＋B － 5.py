c = 0
d = list()

while True:
    a, b = map(int, input().split())
    d.append(a + b)
    c = c + 1
    if a == 0 and b == 0:
        break

e = c - 1

for i in range(e):
    print(d[i])