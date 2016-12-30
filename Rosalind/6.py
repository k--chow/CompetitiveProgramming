n, k = raw_input().split()
n = list(n)
k = list(k)
ans = 0
for i in range(0, len(n)):
    if n[i] != k[i]:
        ans += 1
print ans
