# Developed by "DoKyu Lee"
# Date: 2019.10.01
# Version: 2.0

number = "4177252841"
k=4

def solution(number, k):
    answer = ''
    number = list(number)
    n = len(number)
    prev = number[0]
    idx=1
    head=0
    while k>0 or idx < n:
        temp=[]
        print([number, temp, prev])
        print("head: {}, idx: {}".format(head, idx))	
        if number[idx] > prev:
            ln = idx - head
            if ln <= k:
                k-=ln
                for i in range(idx, len(number)	):
                    temp.append(number[i])
                number = temp[:]
                print(number)
                head = 0
                idx=0
            else:
                k-=ln
                for i in range(head+1, idx):
                    temp.append(number[i])
                print("temp: {}".format(temp))
                for el in temp:
                    number.remove(el)
                head = idx
                print(number)
                #number = temp + number[head:-1]
                
        elif number[idx] is prev:
            head+=1
        print("##############################")
        print([number, temp, prev])
        print("head: {}, idx: {}".format(head, idx))
        print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
        prev = number[idx]
        idx+=1
            
    print(number)
    return answer

solution(number, k)
