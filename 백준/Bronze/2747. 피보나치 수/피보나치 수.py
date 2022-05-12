fibo_list = [0 for i in range(10001)]

n = int(input())

for i in range(n + 1):
    if i <= 1:
        fibo_list[i] = i
    else:
        fibo_list[i] = fibo_list[i - 2] + fibo_list[i - 1]

print(fibo_list[n])