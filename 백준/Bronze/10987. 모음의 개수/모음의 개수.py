s = input()

save = ['a', 'e', 'i', 'o', 'u']

ans = 0

for i in s:
    if i in save:
        ans += 1

print(ans)