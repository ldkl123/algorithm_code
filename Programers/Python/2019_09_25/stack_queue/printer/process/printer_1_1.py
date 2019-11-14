# Developed by "DoKyu Lee"
# Date: 2019.09.25
# Version: 1.1

import queue
import heapq

lst = []
actual_lst = queue.Queue()
q = queue.Queue()
def solution(priorities, location):
    answer = 0
    # To see where is the target
    new_lst = [0]*len(priorities)
    new_lst[location] = 1
    
    # q and actual_list is queue
    insert_queue(q, new_lst)
    insert_queue(actual_lst, priorities)
    priority_queue(lst, priorities)
    
    while True:
        tok = q.get()                   # Tok represent the target, if tok is 1, that is the target
        J = actual_lst.get()           # Get first print which is located at front
        prior = lst[0][1]               # Get high priority
        
        if J < prior:               # If first printer's priority is lower than high priority
            actual_lst.put(J)      # put printer back to the wait list
        else:
            heapq.heappop(lst)         
            answer+=1

            if tok:               # If it is a target  
                break

    
    print(lst)
    print(q.queue)
    return answer

# insert list element to queue
def insert_queue(lst, p):
    for val in p:
        lst.put(val)

# insert list element to priority_queue using max heap
def priority_queue(lst, p):
    for val in p:
        heapq.heappush(lst, (-val, val))
