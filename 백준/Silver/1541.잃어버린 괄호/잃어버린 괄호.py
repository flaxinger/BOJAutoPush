import sys

input = sys.stdin.readline

c = input()

sum = 0
temp = ""
plus = True

for i in range(len(c)):
		
	if(plus):
		if(c[i]=='-'):
			plus = False
			sum+=int(temp)
			temp = ""
		else:
			if(c[i]!='-' and c[i]!='+' and (len(temp)!=0 or c[i]!='0')):
				temp+=c[i]
			elif(len(temp)>0):
				sum+=int(temp)
				temp = ""
		if(i==len(c)-1):
			sum+=int(temp)
	else:
		if(c[i]!='-' and c[i]!='+' and (len(temp)!=0 or c[i]!='0')):
			temp+=c[i]
		elif(len(temp)>0):
			sum-=int(temp)
			temp = ""
		if(i==len(c)-1):
			sum-=int(temp)
print(sum)