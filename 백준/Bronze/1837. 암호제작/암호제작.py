P, K = map(int, input().split())

sosu = [False, False] + [True] * 1000000
primes = []

for i in range(2, 1000001):
    if sosu[i]:
        primes.append(i)
        for j in range(2 * i, 1000001, i):
            sosu[j] = False


for i in primes:
    if i >= K:
        break
    if P % i == 0:
        print(f"BAD {i}")
        exit(0)


print("GOOD")
