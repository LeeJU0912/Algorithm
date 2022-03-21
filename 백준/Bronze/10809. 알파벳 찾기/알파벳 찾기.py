a = list()
for i in range(26):
    a.append(-1)

b = list(input())

for i in range(len(b)):
    for g in range(26):
        
        if ord(b[i]) == (97 + g):
            if a[g] == -1:
                a[g] = i

for i in range(26):
    print(a[i], end=" ")