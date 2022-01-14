def func(a, b):
    if(a//b == a%b):
        return int(a)
    return -1

a = int(input())
b = a+1
result = 0

while(b < a*a):
    result += func(b, a)
    b+=a+1

print(result)