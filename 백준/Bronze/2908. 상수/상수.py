A, B = input().split()

C = ""
D = ""

for i in range(len(A)):
    C = A[i] + C

for i in range(len(B)):
    D = B[i] + D

if int(C) > int(D):
    print(C)
else:
    print(D)
