for _ in range(3):
    N = int(input())

    hap = 0
    for i in range(N):
        hap += int(input())

    if hap == 0:
        print(0)
    elif hap > 0:
        print("+")
    else:
        print("-")