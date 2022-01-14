import math

def func(a, b):
    sum = 0
    min = 0
    for i in range(b-a+1):
        if(math.sqrt(a+i)%1 ==0):
           if(min == 0):
               min = a+i
           sum += a+i
    return min, sum
    
    
a = int(input())
b = int(input())

min, sum = func(a,b)

if(min == 0):
    print(-1)

else:
    print(sum)
    print(min)