T = int(input())

for i in range(T):
    l = list(map(int, input().split()))

    d1 = l[2] ** 2
    d2 = l[5] ** 2
    d1d2_minus = (l[2] - l[5]) ** 2
    d1d2 = (l[2] + l[5]) ** 2
    distance_pow = (l[0] - l[3]) ** 2 + (l[1] - l[4]) ** 2

    if distance_pow == 0:
        if d1d2_minus == 0:
            print("-1")
        else:
            print("0")
    else:
        if distance_pow > d1d2 or distance_pow < d1d2_minus:
            print("0")
        elif distance_pow == d1d2 or distance_pow == d1d2_minus:
            print("1")
        elif d1d2 > distance_pow > d1d2_minus:
            print("2")