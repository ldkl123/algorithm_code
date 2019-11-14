# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.8

def solution(n, lost, reserve):
    lost, reserve = find(lost, reserve)
    answer = n - borrow(lost, reserve)
    return answer

# find the stduent who have a extra clothes but can't lent to another student
def find(lost, reserve):
    new_lost = list(set(lost) - set(reserve))
    new_reserve = list(set(reserve) - set(lost))         # using set function to get non duplicated set
    return new_lost, new_reserve

# Count the number of student who can't borrow
def borrow(lost, reserve):
    n = len(lost)
    count=0
    for st in lost:
        for j, serve in enumerate(reserve):
            if serve is st-1 or serve is st+1:
                reserve[j] = -1            # Make that student not available
                count+=1                   # only have to do is change the reseve element
                break                      # Count if lost student can borrow the clothes
                
    return n - count               # return the number of student who can't borrow

# Result : Accuracy 100%(100%)
