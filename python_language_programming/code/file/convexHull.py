import math
import random
class point:
	def __init__(self,x,y):
		self.x=x
		self.y=y
	def distance(self,p):
		r1=self.x-p.x
		r2=self.y-p.y
		return math.sqrt(r1*r1+r2*r2)
	def __lt__(self,other):
		if self.x==other.x:
			return self.y<other.y
		return self.x<other.x
	def cross(self,a,b):
		return (a.x-self.x)*(b.y-self.y)-(b.x-self.x)*(a.y-self.y)
class points:
	def __init__(self):
		self.ps=[]
		self.tb=[]
	def get_point(self,x,y):
		p=point(x,y)
		self.ps.append(p)
	def sort_ps(self):
		self.ps.sort()
	def get_tubao(self):
		self.sort_ps()
		self.tb.append(self.ps[0])
		for i in range(1,len(self.ps)):
			while len(self.tb)>1 and (self.tb[-2]).cross(self.tb[-1],self.ps[i])>0:
				self.tb.pop()
			self.tb.append(self.ps[i])
		temp=len(self.tb)
		for i in range(len(self.ps)-2,0,-1):
			while len(self.tb)>temp and (self.tb[-2]).cross(self.tb[-1],self.ps[i])>0:
				self.tb.pop()
			self.tb.append(self.ps[i])
	def get_minrec(self):
		get_tubao()
		pass

a=points()
#for i in range(5):
#	x=int(input())#random.uniform(0,100)
#	y=int(input())#random.uniform(0,100)
#	a.get_point(x,y)
a.get_point(1,1)
a.get_point(2,1)
a.get_point(2,2)
a.get_point(2,3)
a.get_point(3,2)
a.sort_ps()
for p in a.ps:
	print(p.x,p.y)
a.get_tubao()
for p in a.tb:
	print(p.x,p.y)