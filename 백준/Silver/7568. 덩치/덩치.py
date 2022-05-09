arr = list()
arr2 = list()
arr3 = list()

a = 1
b = 0
c = 0
countx = list()

t = int(input())

for i in range(t):
    x, y = map(int,input().split())
    arr2.append(x)
    arr3.append(y)
    countx.append(1)

for i in range(t):
    for n in range(t):
        if arr2[i] - arr2[n] < 0 and arr3[i] - arr3[n] < 0:
            countx[i] = countx[i] + 1
 

for i in range(t):
    print(countx[i])