import sys

a = int(input())
n = list()

for i in range(a):
    b, c = map(int,sys.stdin.readline().split())
    d = b + c
    n.append(d)

for i in range(a):
    print(n[i])