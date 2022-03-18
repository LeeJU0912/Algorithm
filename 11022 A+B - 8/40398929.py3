arr = list()
arr2 = list()
arr3 = list()

b = int(input())

for i in range(b):
    c, d = map(int,input().split())
    arr.append(c + d)
    arr2.append(c)
    arr3.append(d)

for i in range(b):
    print("Case #%d: %d + %d = %d" % (i + 1, arr2[i], arr3[i], arr[i]))