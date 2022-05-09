c = 0
d = list()


while True:
    try:
        
        a, b = map(int, input().split())
        d.append(a + b)
        c = c + 1
    except:
        break
    
for i in range(c):
    print(d[i])