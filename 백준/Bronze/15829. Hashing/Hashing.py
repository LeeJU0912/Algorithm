a = int(input())
b = list(input())

c = 0

for i in range(len(b)):
    c += (ord(b[i]) - 96) * (31 ** i)

c = c % 1234567891

print(c)