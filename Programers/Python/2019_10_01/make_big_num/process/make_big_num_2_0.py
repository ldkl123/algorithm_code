# Developed by "DoKyu Lee"
# Date: 2019.10.01
# Version: 2.0

def solution(number, k):
    answer = ''
    number = list(number)
    n = len(number)
    prev = number[0]
    idx=1
    head=0
    temp=[]
    while k>0:
        if number[idx] > prev:
            ln = idx - head
            if ln <= k:
                k-=ln
                for i in range(idx, n):
                    temp.append(number[i])
                number = temp
                head = idx
            else:
                for i in range(head, idx):
                    temp.append(number[i])
                temp_n = len(temp)
                count=0
                while True:
                    el = min(temp)
                    temp.remove(el)
                    count+=1
                    if count is k:
                        break
                head = idx
                number = temp + number[head:-1]
                k=0
        idx+=1
            
    print(number)
    return answer

# Reuslt: error
