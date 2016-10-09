a = 0
c = 0
g = 0
t = 0
seq = raw_input()
for i in seq:
    if i == 'A':
        a+=1
    elif i == 'C':
        c+=1
    elif i == 'G':
        g+=1
    else:
        t+=1
print str(a) + " " + str(c) + " " + str(g) + " " + str(t)
