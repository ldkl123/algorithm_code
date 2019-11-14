# Developed by "DoKyu Lee"
# Date: 2019.09.24
# Version: 2.5

visited=[]

def solution(n, computers):
    global visited               # visited have to be global variable
    answer=0
    visited = [0]*n         # visited history matrix, changed to 1 dimension
    
    for i in range(n):
        answer += DFS_before(computers, i, n)     # counting network number
        
    return answer

# middle function before doing DFS
def DFS_before(computers, start, n):
    if visited[start]:         # if start point was visited, that node is connected by something else
        return 0
    else:
        visited[start] = 1     # make sure starting point is visited
        return DFS(computers, start, n) + 1

# Depth First Search: find conected network
def DFS(computers, start, n):
    for i in range(0, n):                      # get rid of visited[start][start]
        if visited[i] == 0 and computers[start][i] == 1:
            visited[i] = 1                                   # visited table have to be transpose matrix
            return DFS(computers, i, n)
        
    return 0

# Result: Accuracy 30.8% (100%)
