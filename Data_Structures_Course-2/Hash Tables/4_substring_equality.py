# python3
import sys

hashes=list()
calc=[0]
calc1=[1]
def hashf(s,i):
	x=53
	m1=1000000007
	m2=1000000009
	code1=((hashes[i-1][0]*x)%m1+ord(s[i])%m1)%m1
	code2=((hashes[i-1][1]*x)%m2+ord(s[i])%m2)%m2

	# for i in range(start,end+1):
	# 	code1=(code1*x+ord(s[i]))%m1
	# 	code2=(code2*x+ord(s[i]))%m2

	return (code1,code2)



def hascall(s):
	hashes.append((ord(s[0])%1000000007,ord(s[0])%1000000009))
	for i in range(1,len(s)):
		hashes.append(hashf(s,i))
class Solver:
	def __init__(self, s):
		self.s = s


	def ask(self, a, b, l):
	# return s[a:a+l] == s[b:b+l]
		temp=0
		x=53
		m1=1000000007
		m2=1000000009
		if(l in calc):
			temp=calc1[calc.index(l)]
		else:
			temp=pow(x,l)
			calc.append(l)
			calc1.append(temp)
		y1=temp%m1
		y2=temp%m2
		if(a==0):
			hasha=hashes[l-1]
		else:
			hasha=((hashes[a+l-1][0]-y1*hashes[a-1][0])%m1,(hashes[a+l-1][1]-y2*hashes[a-1][1])%m2)
		if(b==0):
			hashb=hashes[l-1]
		else:
			hashb=((hashes[b+l-1][0]-y1*hashes[b-1][0])%m1,(hashes[b+l-1][1]-y2*hashes[b-1][1])%m2)
		if(hasha[0]==hashb[0] and hasha[1]==hashb[1]):
				return True
		return False

s = sys.stdin.readline()
q = int(sys.stdin.readline())
solver = Solver(s)
hascall(s)
for i in range(q):
	a, b, l = map(int, sys.stdin.readline().split())
	print("Yes" if solver.ask(a, b, l) else "No")


# trololo
# 4
# 0 0 7
# 2 4 3
# 3 5 1
# 1 3 2
