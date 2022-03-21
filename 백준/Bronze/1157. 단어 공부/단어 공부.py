a = list()
d = 0
for i in range(26):
    a.append(0)
    
b = list(input())

for i in range(len(b)):
    f = ord(b[i])    
    if 97 <= ord(b[i]) and ord(b[i]) <= 122:
        f = ord(b[i]) - 32
    a[f - 65] += 1

for i in range(26):
    if a[i] == max(a):
        d += 1

if d > 1:
    print("?")

else:
    print(chr(65 + a.index(max(a))))