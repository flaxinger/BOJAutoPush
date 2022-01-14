def func2(a):
    if(a>0):
        if(a%10 == 7 or a%10 == 4):
            return func2(a//10)
        else:
            return False
    if(a== 0): return True
    else: return False

def func(a):
    while(not func2(a)):
        a-=1
    return a

a = int(input())
print(func(a))