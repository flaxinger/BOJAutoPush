def func(a, b):
    count = 0
    idx = a.index(b)
    if(idx < len(a)/2):
        while(a[0]!=b):
            temp = a[0]
            a.remove(a[0])
            a.insert(len(a), temp)
            count +=1
        a.remove(a[0])
    else:
        while(a[-1]!=b):
            temp = a[-1]
            a.remove(a[-1])
            a.insert(0, temp)
            count +=1
        temp = a[-1]
        a.remove(a[-1])
        a.insert(0, temp)
        count +=1
        a.remove(a[0])
    return a, count

a= input()
length, length2 = a.split(" ")
length = int(length)
length2 = int(length2)
arg = str(input())
arg = [int(i) for i in arg.split(' ')]
ans_list = []

total = 0

for i in range(length):
    ans_list.append(i+1)

for i in range(length2):
    ans_list, temp = func(ans_list, arg[i])
    total+=temp

print(total)