import copy

one_len, two_len = [int(i) for i in input().split(' ')]

one = []
two = []

[one.append(int(i)) for i in input().split(' ')]
[two.append(int(i)) for i in input().split(' ')]

total = one_len+two_len
one_len -=1
two_len -=1
one.sort()
two.sort()
while(one_len >= 0 and two_len >= 0):
    #print("currently at ol: %d, tl: %d" % (one_len, two_len))
    if(one[one_len]<two[two_len]):
        two_len-=1
        #print("\ttwo_len")
    elif(one[one_len] > two[two_len]):
        one_len-=1
        #print("\tone_len")
    elif(one[one_len] == two[two_len]):
        total-=2
        one_len-=1
        two_len-=1
        #print("\tthe same")


print(total)