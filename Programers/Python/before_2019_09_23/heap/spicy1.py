############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.19         #
# Accuracy: 76.2%          #
# Effeciency: 0%           #
############################

def solution(scoville, K):
    answer = 0
    size = len(scoville)
    heap_sort(scoville)
    #print(scoville)
    while(size > 1):
        run(scoville)
        answer+=1
        if check(scoville, K):
            break
        size-=1
    if size == 1:
        answer = -1
    print(answer)
    return answer

def check(array, K):
    for val in array:
        if val < K:
            return False
    return True
def run(array):
    idx = len(array) -1
    mix = array[idx] + 2*array[idx-1]
    del array[idx]
    del array[idx-1]
    array.append(mix)
    heap_sort(array)

def heap_sort(array):
    size = len(array)
    for i in range(int((size/2)-1), -1, -1):
        heap(array, size, i)    
    for i in range(size-1, 0, -1):
        root = array[0]
        array[0] = array[i]
        array[i] = root    
        heap(array, i, 0)
        
    

def heap(array, size, idx):
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
        
        heap(array, size, p)
        
        
