n, k = raw_input().split()
n = int(n)
k = int(k)
s1 = list()
for i in range(0, n):
    if (i == 0) or (i == 1):
        s1.append(1)
    else:
        s1.append(s1[i-1] + s1[i-2]*k)
print s1[n-1]
