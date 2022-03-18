a = int(input())
b = list(map(int, input().split()))
while len(b) == a :
    n = min(b) * max(b)
    print(n)
    break