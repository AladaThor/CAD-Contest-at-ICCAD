#This is a python file
import sys
sA = []
sB = []
sq = []
def rr(self, old, new, *max):
	cnt = len(self)
	if max and str(max[0]).isdigit():
		cnt = max[0]
	return new.join(self.rsplit(old, cnt))

def Ap(self, t):
	if len(self.d) > len(t):
		return True
	elif len(self.d) < len(t):
		return False
	else:
		if self.d > t:
			return True
		else:
			return False


def sw(x):
	return {
		'0': 0,
		'1': 1,
		'2': 2,
		'3': 3,
		'4': 4,
		'5': 5,
		'6': 6,
		'7': 7,
		'8': 8,
		'9': 9,
		'a': 10,
		'b': 11,
		'c': 12,
		'd': 13,
		'e': 14,
		'f': 15,
		'g': 16,
		'h': 17,
		'i': 18,
		'j': 19,
		'k': 20,
		'l': 21,
		'm': 22,
		'n': 23,
		'o': 24,
		'p': 25,
		'q': 26,
		'r': 27,
		's': 28,
		't': 29,
		'u': 30,
		'v': 31,
		'w': 32,
		'x': 33,
		'y': 34,
		'z': 35,
		'A': 36,
		'B': 37,
		'C': 38,
		'D': 39,
		'E': 40,
		'F': 41,
		'G': 42,
		'H': 43,
		'I': 44,
		'J': 45,
		'K': 46,
		'L': 47,
		'M': 48,
		'N': 49,
		'O': 50,
		'P': 51,
		'Q': 52,
		'R': 53,
		'S': 54,
		'T': 55,
		'U': 56,
		'V': 57,
		'W': 58,
		'X': 59,
		'Y': 60,
		'Z': 61,
		'@': 62,
		'#': 63
	}[x]

class N:
	def __init__(self, d):
		self.lt = None
		self.ri = None
		self.ro = None
		self.v = False
		self.d = d
		self.s = 0

	def ins(self, d):
		if self.d:
			cur = self
			while True:
				if Ap(cur, d) == True:
					if cur.lt is None:
						cur.lt = N(d)
						cur.lt.ro = cur
						break
					else:
						cur = cur.lt
				elif Ap(cur, d) == False:
					if cur.ri is None:
						cur.ri = N(d)
						cur.ri.ro = cur
						break
					else:
						cur = cur.ri
				else:
					break

	def ptA(self):
		cur = self
		while True:
			if cur.lt and cur.lt.v == False:
				cur = cur.lt
			elif (cur.lt == None or cur.lt.v == True) and cur.v == False:
				sA.append(cur.d)
				cur.v = True
			elif cur.ri and cur.v == True and cur.ri.v == False:
				cur = cur.ri
			else:
				if cur.ro:
					cur = cur.ro
				else:
					break

	def ptB(self):
		cur = self
		while True:
			if cur.lt and cur.lt.v == False:
				cur = cur.lt
			elif (cur.lt == None or cur.lt.v == True) and cur.v == False:
				sB.append(cur.d)
				cur.v = True
			elif cur.ri and cur.v == True and cur.ri.v == False:
				cur = cur.ri
			else:
				if cur.ro:
					cur = cur.ro
				else:
					break

fp = open(sys.argv[1], 'r', encoding = 'UTF-8')
line = fp.readlines()
fp.close()
L1 = line[0]
L2 = L1.replace(',', " ")
L3 = L2.replace('"', " ")
L4 = L3.replace("[", " ", 2)
L5 = rr(L4, "]", " ", 2)
L6 = L5.split()

a6 = []
b6 = []
mi = int(len(L6) // 2)
for i in range(mi-1):
	a6.append(L6[i])
mi += 1
for x in range(mi, len(L6), 1):
	b6.append(L6[x])

aS = []
bS = []
fot = open(sys.argv[2], 'w')
fot.write("{\n")

dA = list(set(a6) - set(b6))
dB = list(set(b6) - set(a6))
sa = list(set(a6) - set(dA))
for i in range(len(sa)):
	fot.write('	"'+sa[i]+'": "'+sa[i]+'",\n')
aS = dA
bS = dB

roA = N(aS[0])
for i in range(1, len(aS), 1):
	roA.ins(aS[i])
roA.ptA()

roB = N(bS[0])
for i in range(1, len(bS), 1):
	roB.ins(bS[i])
roB.ptB()
for i in range(len(sA)):
	fot.write('\t"'+sA[i]+'": ')
	tb = 0
	for j in range(len(sq[i])):
		k = sw(sq[i][j])
		tb += k * pow(64, j)
	if i != (len(sA)-1):
		fot.write('"'+sB[tb]+'",\n')
	else:
		fot.write('"'+sB[tb]+'"\n')

fot.write("}")
fot.close()