
def f(n):
	if n == 1:
		return 1
	else:
		return (n-1)*2

while True:
	n = input()
	if n =='':
		sys.exit(0)
	else:
	   n=int(n)
	   n=f(n)
	   print n


