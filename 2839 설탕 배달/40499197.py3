a = int(input())

b = int(a / 5)

if a < 5:
    if a == 3:
        print("1")
    else:
        print("-1")

elif b == 0:
    print(b)
else:
    for i in range(b + 1):
        c = int((a - 5 * (b - i)) / 3)
        d = int((a - 5 * (b - i)) % 3)
        if d == 0:
            print(b - i + c)
            break
        if b - i == 0 and c != 0:
            print("-1")
            break