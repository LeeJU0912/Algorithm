a, b = map(int,input().split())


c = [[0 for i in range(a)] for j in range(b)]

d = list()
e = list()
t = list()

counter = 0
one_counter = 0

for i in range(b):
    d = list(map(int,input().split()))
    for g in range(a):
        c[i][g] = d[g] #전체 2차원 배열
        if d[g] == 1:  #첫번째 1 검출기
            e.append([i, g])
        if d[g] == 0:
            t.append([i, g])

while True: #횟수 체크 반복문

    h = list()   
    for s in range(len(e)): #1블록 하나씩 검증 반복 리스트 e
        
        i = e[s][0]
        g = e[s][1]
        
        if i == 0: #첫번째줄 처리

            if g == 0:
                if c[i][g] == 1: #왼쪽 위 구석
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])


            elif g == a - 1:
                if c[i][g] == 1: #오른쪽 위 구석
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])


                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])


            else:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])


                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])


                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])

            continue
                            
        if i == b - 1: #마지막줄 처리

            if g == 0:
                if c[i][g] == 1: #왼쪽 아래 구석
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])
                        
            elif g == a - 1:
                if c[i][g] == 1: #오른쪽 아래 구석
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])

            else:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])

                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])

            continue
        
        else:
            if g == 0:
                if c[i][g] == 1:
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])

            elif g == a - 1:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])
                        
            else:
                if c[i][g] == 1:
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        h.append([i, g + 1])

                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        h.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        h.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        h.append([i + 1, g])

            continue

    if len(h) == 0:
        break

    counter += 1
    
    e = list()
    for s in range(len(h)): #1블록 하나씩 검증 반복 리스트 h
        
        i = h[s][0]
        g = h[s][1]
        
        if i == 0: #첫번째줄 처리

            if g == 0:
                if c[i][g] == 1: #왼쪽 위 구석
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])

            elif g == a - 1:
                if c[i][g] == 1: #오른쪽 위 구석
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])

            else:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])

            continue
                            
        if i == b - 1: #마지막줄 처리

            if g == 0:
                if c[i][g] == 1: #왼쪽 아래 구석
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])
                        
            elif g == a - 1:
                if c[i][g] == 1: #오른쪽 아래 구석
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])

            else:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])

            continue
        
        else:
            if g == 0:
                if c[i][g] == 1:
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])

            elif g == a - 1:
                if c[i][g] == 1:
                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])
                        
            else:
                if c[i][g] == 1:
                    if c[i][g + 1] == 0:
                        c[i][g + 1] = 1
                        e.append([i, g + 1])

                    if c[i][g - 1] == 0:
                        c[i][g - 1] = 1
                        e.append([i, g - 1])

                    if c[i - 1][g] == 0:
                        c[i - 1][g] = 1
                        e.append([i - 1, g])

                    if c[i + 1][g] == 0:
                        c[i + 1][g] = 1
                        e.append([i + 1, g])

            continue
   
    if len(e) == 0:
        break
    
    counter += 1

for p in range(len(t)):
    i = t[p][0]
    g = t[p][1]
    
    if c[i][g] == 0:
        counter = -1
        break
       
print(counter)