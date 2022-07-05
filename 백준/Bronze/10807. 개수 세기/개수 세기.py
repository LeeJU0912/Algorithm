a = int(input())

counter = 0

l = list(map(int, input().split()))

d = int(input())

for i in range(a):
    if l[i] == d:
        counter += 1

print(counter)