import time

a, b = [int(i) for i in input().split(" ")]

if(a == 0):
	print(1)
else:
	#base = int((b/a)*100)
	base = int(b*100/a)
	#print(base)
	min = 0
	max = a
	if(base >= 99):
		print(-1)
	else:
		while(min + 1 < max):
			mid = (min+max)//2
			#print("min: %d, mid: %d, max: %d\tnow: %0.2f\tbase: %0.2f" % (min, mid, max, (b+mid)/(a+mid)*100, base))
			if(int((b+mid)/(a+mid)*100) != base):
				max = mid
			else:
				min = mid
			#time.sleep(0.5)
		if(int((b+min)/(a+min)*100)!=base):
			print(min)
		else:
			print(max)