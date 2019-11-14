############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.20         #
# Accuracy: 71.4%          #
# Effeciency: 23.8%        #
############################

import heapq     #라이브러리 사용

def solution(scoville, K):
    heap=[]
    answer=0
    heap_sort(heap, scoville)
    size = len(heap)
    while(size>1):
        s1 = heapq.heappop(heap)
        s2 = heapq.heappop(heap)
        heapq.heappush(heap,s1+2*s2)
        size-=1
        answer+=1
        if check(heap, K):
            break
        
    if size <=1:
        answer=-1
    return answer

def check(heap, K):
    if heap[0] < K:
        return False
    return True

def heap_sort(heap, scoville):
    for val in scoville:
        heapq.heappush(heap, val)
