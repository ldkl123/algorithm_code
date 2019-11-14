# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.1

def solution(n, lost, reserve):
    answer = n - borrow(lost, reserve)
    return answer

def borrow(lost, reserve):
    n = len(lost)
    count=0
    for st in lost:
        for j, serve in enumerate(reserve):
            if serve is st-1 or serve is st+1:
                reserve[j] = 0             # Don't need to change lost element to 0 
                count+=1                   # only have to do is change the reseve element
                break                      # Count if lost student can borrow the clothes
                
    return len(lost) - count               # return the number of student who can't borrow

# Result : Accuracy 50%(100%)
