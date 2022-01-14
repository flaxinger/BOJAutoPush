def checking(arr, num, x, y, a):
    if(arr[x + num][y]==a and arr[x + num][y + num] == a and arr[x][y + num] == a):
        return True
    else:
        return False

r, c = [int(i) for i in input().split(" ")]
l = []
for i in range(r):
    temp =[]
    [temp.append(int(j)) for j in input()]
    l.append(temp)


result = 1
for i in range(r):
    for j in range(c):
        adding = 0
        while(adding+i >0 and adding+j > 0):
            adding -=1
            if(checking(l, adding, i, j, l[i][j])):
                temp = (adding+1)**2
                if(temp > result):
                    result = temp
        adding = 0
        while(adding+i < r-1 and adding+j < c-1):
            adding +=1
            if(checking(l, adding, i, j, l[i][j])):
                temp = (adding+1)**2
                if(temp > result):
                    result = temp
        #print("gor to (%d, %d) result is %d" % (i, j, result))

print(result)