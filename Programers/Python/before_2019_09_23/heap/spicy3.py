############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.19         #
# Accuracy: 71.4%          #
# Effeciency: 0%           #
############################

def solution(scoville, K):
    answer = 0
    size = len(scoville)
    first_heap_sort(scoville, size)
    while(size > 1):
        s1, size = delete_heap(scoville, size)
        s2, size = delete_heap(scoville, size)
        size = run(scoville, size, s1, s2)
        answer+=1
        if scoville[0] > K:
            break
            
    if size == 1:
        answer = -1
    return answer

def check(array, size, K):
    if array[size-1] < K:
        return False
    return True

def run(array, size, first, second):
    mix = first + 2*second
    array.append(mix)
    size+=1
    insert_min_heap(array, size)
    return size

def delete_heap(array, size):
    target = array[0]
    array[0] = array[size-1]
    del array[size-1]
    size-=1
    min_heap(array, size, 0)
    return target, size

def insert_min_heap(array, size):
    idx = size-1    
    while(idx > 0):
        p = int((idx/2)-1)
        if array[p] > array[idx]:
            temp = array[p]
            array[p] = array[idx]
            array[idx] = temp
        idx = p


    
def first_heap_sort(array, size):
    for i in range(int((size-1/2)-1), -1, -1):
        min_heap(array, size, i)    

def min_heap(array, size, idx):
    p = idx 
    l = 2*idx+1
    r = 2*idx+2
    
    if l < size and array[l] < array[p]:
        p = l
    if r < size and array[r] < array[p]:
        p = r
        
    if idx != p:
        temp = array[p]
        array[p] = array[idx]
        array[idx] = temp
        
        min_heap(array, size, p)
