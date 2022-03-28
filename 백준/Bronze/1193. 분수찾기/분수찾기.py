a = int(input())
up = 0
i = 1

if a == 1:
    print("1/1")

else:
    
    while a > i:

        a -= i
        i += 1
        if up == 0:
            up = 1
        elif up == 1:
            up = 0

    if up == 1:
        print(a, "/", (i - a + 1), sep='')
    elif up == 0:
        print((i - a + 1), "/", a, sep='')