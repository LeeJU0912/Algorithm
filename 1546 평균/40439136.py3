a = int(input())

b = list(map(int,input().split()))

c = 0

d = 0

e = 0

f = max(b)

for n in range(a):
    b[n] = (b[n] / f) * 100
    c = c + b[n]

d = c / a

print(d)
