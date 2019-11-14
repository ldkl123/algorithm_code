############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.19         #
# Accuracy: 71.4%          #
# Effeciency: 0%           #
############################

# Developed by "DoKyu Lee"
# Date: 2019.09.19
# Accuracy: 76.2%
# Effeciency: 0%

def solution(scoville, K):
    answer = 0
    size = len(scoville) 
    heap_sort(scoville)
    while(size > 1):
        run(scoville)
        size-=1            # run을 하게 되면 size가 줄어들기 때문에 바로 감소시켜줘야한다. 
        answer+=1
        if check(scoville,size, K):
            break

        
    if size == 1:
        answer = -1
    return answer

def check(array, size, K):
    if array[size-1] < K:     # array[-1]는 마지막 원소의 위치를 모르기 때문에 O(n)의 복잡도가 걸릴 것이다. 따라서 가지고 있는 size 정보를 사용하는게 좋다.
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
        
        
