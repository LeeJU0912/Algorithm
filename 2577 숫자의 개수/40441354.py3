a = int(input())
b = int(input())
c = int(input())

d = a * b * c

e = list(0 for i in range(10))

while d >= 1:
    f = int(d % 10)
    d = int(d / 10)
    e[f] = e[f] + 1

for x in range(10):
    print(e[x])