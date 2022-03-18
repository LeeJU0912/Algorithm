a = list()
b = list()

c = 0

while True:
    d = int(input())

    if d == 0:
        break

    c = int(c + 1)
    
    a.append(d)

for i in range(c):

    f = 0
    g = -1

    y = a[i]

    b = list()
    
    while y >= 1:

        e = int(y % 10)
        y = int(y / 10)
        f = f + 1
        b.append(e)


    if a[i] < 10:
        print("yes")
        continue
        
    if a[i] >= 10 and a[i] < 100:
        if b[0] == b[1]:
            print("yes")
            continue
        else:
            print("no")
            continue

    p = int(f / 2)

    
    for k in range(p):
        if k <= p - 1:
            if k == p - 1:
                if b[k] != b[g]:
                    print("no")
                    break
                else:
                    print("yes")
                    break
            
            if b[k] == b[g]:
                g = g - 1

            else:
                print("no")
                break