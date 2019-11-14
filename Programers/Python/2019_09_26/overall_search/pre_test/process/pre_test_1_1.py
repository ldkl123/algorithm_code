# Developed by "DoKyu Lee"
# Date: 2019.09.26
# Version: 1.1

import heapq
s2_lst = [1, 3, 4, 5]
s3_lst = [3, 1, 2, 4, 5]

def solution(answers):
    answer = []
    answer = find(answers)
    return answer

def find(answers):
    s = [0]*3
    s_ans = [0]*3
    count=0
    j=0
    z=0
    for i, ans in enumerate(answers):
        #student 1
        s_ans[0] = i%5 + 1
        #student 2
        if (i+1)%2:
            s_ans[1] = 2
        else:
            s_ans[1] = s2_lst[z]
            z = (z%3)+1               # z = (z%4)+1 => if z is 3, z updates to 4. So index dump 
        #student 3
        if count < 1:
            s_ans[2] = s3_lst[j]
            count+=1
        else:
            s_ans[2] = s3_lst[j]
            count=0
            j = (j%4)+1              # also
        for i in range(3):
            if s_ans[i] == ans:
                s[i]+=1

    return judge(s)
# To find student who got high score(Using max heap)
def judge(s):
    heap = []
    answer = []
    for i, st in enumerate(s):
        heapq.heappush(heap, (-st, i+1))
        
    while len(heap):
        if len(heap)==1:
            answer.append(heap[0][1])
            break

        temp = heapq.heappop(heap)
        answer.append(temp[1])
        if -heap[0][0] != -temp[0]:
            break
    return answer

# Result: Accuracy 64.3% (100%)
