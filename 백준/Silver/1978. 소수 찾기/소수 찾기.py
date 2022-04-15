numlist = list()
sosu = list(range(1001))
counter = 0

sosu[1] = 0

a = int(input())
numlist = list(map(int,input().split()))

for i in range(2, max(numlist) + 1):
    for g in range (2, max(numlist) + 1):
        if sosu[g] != i and sosu[g] % i == 0:
            sosu[g] = 0

for i in range(a):
    if numlist[i] == sosu[numlist[i]]:
        counter += 1
        
print(counter)