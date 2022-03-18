a = int(input())

b = 1

c = a - 1

for i in range(a):
    for i in range(c):
        print(" ", end='')
    for i in range(b):
        print("*", end='')
    print("")
    b = b + 1
    c = c - 1
