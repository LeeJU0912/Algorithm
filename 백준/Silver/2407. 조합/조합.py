temp = [[0 for i in range(101)] for j in range(101)]

def combination(n, r):
    if temp[n][r] != 0:
        return temp[n][r]
    elif n == r or r == 0:
        temp[n][r] = 1
        return 1
    else:
        temp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r)
        return temp[n][r]



a, b = map(int,input().split())

c = combination(a, b)


print(c)