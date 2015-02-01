def gcd (a, b):
	if b == 0:
		return a
	else:
		return gcd (b, a % b) 
 
t = int(input())
while t != 0:
	t = t - 1
	a, b = [int(x) for x in input().split()]
	print (gcd(a, b))
