def col(a):
    total = 0
    for i in range(len(a)):
        counter = 0
        for j in range(len(a)):
            if(a[j][i] == '.'):
                counter+=1
            else:
                counter = 0
            if(counter == 2):
                total +=1
    return total

def row(a):
    total = 0
    for i in range(len(a)):
        counter = 0
        for j in range(len(a)):
            if(a[i][j] == '.'):
                counter+=1
            else:
                counter = 0
            if(counter == 2):
                total +=1
    return total

a = int(input())
result = []
for i in range(a):
    result.append(input())

if(a == 0):
    print("%d %d" % (0, 0))
else:
    print("%d %d" % (row(result), col(result)))
    
    