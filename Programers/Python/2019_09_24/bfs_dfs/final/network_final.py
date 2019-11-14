# Developed by "DoKyu Lee"
# Date: 2019.09.24
# Version: 2.7

visited=[]
dic = {0:'a', 1:'b', 2:'c', 3:'d'}     # to debug

def solution(n, computers):
    global visited               # visited have to be global variable
    answer=0
    visited = [0]*n         # visited history matrix, changed to 1 dimension
    
    for i in range(n):
        answer += DFS(computers, i, n)     # counting network number
        
    return answer

# Depth First Search: find conected network
def DFS(computers, start, n):
    count=0                                 # count if going to visit
    for i in range(n):                      # get rid of visited[start][start]       
        if visited[i] == 0 and computers[start][i] == 1:
            count+=1
            visited[i] = 1                                   # visited table have to be transpose matrix
            DFS(computers, i, n)
    if not count:
        return 0
    else:
        return 1

# Result: Accuracy 100% (100%)
