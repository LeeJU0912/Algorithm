a, k = map(int,input().split())
b = list(map(int,input().split()))

c = b[2]
d = 0
g = 0

for i in range(a - 2):

    for e in range(i + 1, a - 1):

        for f in range(e + 1, a):

            


            d = b[i] + b[e] + b[f]

            if d > k:
                d = d - b[f]
                continue

            if d == k:
                g = d
                break

            if g <= d:
                g = d


print(g)