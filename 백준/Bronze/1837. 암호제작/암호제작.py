P, K = map(int, input().split())

for i in range(2, 1000001):
    if i >= K:
        break
    if P % i == 0:
        print(f"BAD {i}")
        exit(0)

print("GOOD")
