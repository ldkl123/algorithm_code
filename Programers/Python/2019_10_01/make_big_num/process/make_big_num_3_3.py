# Developed by "DoKyu Lee"
# Date: 2019.10.02
# Version: 3.3


def solution(number, k):
    answer = ''
    number = list(number)
    n = len(number)
    head=0
    i=0
    prev = number[0]
    while i<n:
        print("{}, {}".format((number), head))
        if number[i] > prev:             # compare each neighbor number and if next number is bigger than previous number, have to remove small number before number[i]
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
        prev = number[i]                # update the prev number
        i+=1
    for j in range(k):
        number.pop()
    print("{},{}".format(number, k))
    answer = ''.join(number)
    return answer


#removed the over index error 
#Result: Accuracy 16.7%(100%), 2 run time error, 1 time out
