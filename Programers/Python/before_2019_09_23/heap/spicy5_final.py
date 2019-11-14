############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.20         #
# Accuracy: 76.2%          #
# Effeciency: 23.8%        #
# Total: 100&              #
############################

import heapq     #라이브러리 사용

def solution(scoville, K):
    heap=[]
    answer=0
    is_ok=False
    heap_sort(heap, scoville)
    size = len(heap)
    while(size>1):
        s1 = heapq.heappop(heap)
        s2 = heapq.heappop(heap)
        heapq.heappush(heap,s1+2*s2)
        answer+=1
        size-=1
        if check(heap, K):
            is_ok=True
            break
            
    if not is_ok:
        answer=-1
    return answer

def check(heap, K):
    if heap[0] < K:
        return False
    return True

def heap_sort(heap, scoville):
    for val in scoville:
        heapq.heappush(heap, val)
