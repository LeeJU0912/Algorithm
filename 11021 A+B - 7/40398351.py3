arr = list()

b = int(input())

for i in range(b):
    c, d = map(int,input().split())
    arr.append(c + d)

for i in range(b):
    print("Case #%d: %d" % (i + 1, arr[i]))
