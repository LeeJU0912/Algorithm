A = int(input())
B = int(input())
C = int(input())

D = A * B * C

answer = [0 for i in range(10)]

while D != 0:
    answer[D % 10] += 1
    D //= 10

for i in answer:
    print(i)
