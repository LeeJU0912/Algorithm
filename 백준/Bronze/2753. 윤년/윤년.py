a = int(input())

b = a % 400
c = a % 100
d = a % 4

if b == 0:
    print("1")
elif c != 0 and d == 0:
    print("1")
else:
    print("0")
