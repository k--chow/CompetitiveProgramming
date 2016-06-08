def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def f(a, b):  
    if a == b:  
        return 1  
    else:  
        return factorial((a-b)+b-1)/(factorial(a-b)*factorial(b-1))

cases = int(raw_input())  
for t in range(0, cases):  
	a, b = map(int, raw_input().split())
	ans = f(a, b)
    	print "%d" % ans