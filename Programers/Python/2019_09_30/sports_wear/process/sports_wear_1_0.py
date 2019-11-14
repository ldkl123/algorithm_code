# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.0

def solution(n, lost, reserve):
    answer = n - borrow(lost, reserve)
    return answer

def borrow(lost, reserve):
    n = len(lost)
    count=0
    for i, st in enumerate(lost):
        for i, serve in enumerate(reserve):
            if serve == st-1 or serve == st+1:
                lost[i] = -1
                reserve[i] = -1
                count+=1
                break
                
    return len(lost) - count

# Result : Accuracy 50%(100%)
