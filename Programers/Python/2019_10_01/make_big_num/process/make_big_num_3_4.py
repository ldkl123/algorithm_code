# Developed by "DoKyu Lee"
# Date: 2019.10.02
# Version: 3.4


def solution(number, k):
    answer = ''
    number = list(number)
    n = len(number)
    head=0
    i=0
    prev = number[0]
    flag = False
    while i<n:
        #print("{}, ({}, {}), k:{}, prev:{}".format((number), head, i, k, prev))
        if number[i] > prev:             # compare each neighbor number and if next number is bigger than previous number, have to remove small number before number[i]
            flag = False
            ln = i - head
            if ln >= k:                  # if head to i-1th element length is larger than k
                for j in range(k):
                    m = min(number[head:i])
                    number.remove(m)
                    i-=1
                    k=0
                break
            else:
                k-=ln                   # if head to i-1th element length is smaller than k, reduce the k             
                for j in range(ln):
                    m = min(number[head:i])
                    number.remove(m)
                    i-=1
                head = i
        if number[i] is prev and flag is False:
            prev = number[i]                # update the prev number
            flag = True
        elif number[i] is not prev and flag is False:
            prev = number[i]
        i+=1
    for j in range(k):
        number.pop()
    #print("{},{}".format(number, k))
    answer = ''.join(number)
    return answer



#Result: Accuracy 25%(100%), 7 run time error
