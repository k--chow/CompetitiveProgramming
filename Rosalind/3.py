seq = raw_input()
s = list(seq)
s.reverse()
for i in range(0, len(s)):
    if s[i] == 'A':
        s[i] = 'T'
    elif s[i] == 'T':
        s[i] = 'A'
    elif s[i] == 'C':
        s[i] = 'G'
    else:
        s[i] = 'C'
print ''.join(s)
