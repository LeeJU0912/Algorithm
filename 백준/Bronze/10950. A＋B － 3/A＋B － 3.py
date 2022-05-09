c = int(input())
d = list()

for i in range(c):
    a, b = map(int, input().split())
    d.append(a + b)
for i in range(c):
    print(d[i])