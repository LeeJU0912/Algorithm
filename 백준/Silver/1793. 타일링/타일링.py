import sys

DP = [0 for _ in range(251)]

DP[0] = 1
DP[1] = 1
DP[2] = 3

for i in range(3, 251):
    DP[i] = DP[i-1] + DP[i-2] * 2

while True:
    Input = sys.stdin.readline()

    if Input == "":
        break
    n = int(Input)

    print(DP[n])