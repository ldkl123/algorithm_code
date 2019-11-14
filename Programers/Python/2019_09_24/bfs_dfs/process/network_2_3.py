# Developed by "DoKyu Lee"
# Date: 2019.09.24
# Version: 2.3

visited=[]

def solution(n, computers):
    global visited               # visited have to be global variable
    answer=0
    visited = [[0]*n for x in range(n)]         # visited history matrix
    
    for i in range(n):
        answer += DFS_before(computers, i, n)     # counting network number
    return answer

# middle function before doing DFS
def DFS_before(computers, start, n):
    if visited[start][start]:         # if start point was visited, that node is connected by something else
        return 0
    else:
        return DFS(computers, start, n)

# Depth First Search: find conected network
def DFS(computers, start, n):
    for i in range(start, n):                      # get rid of visited[start][start]
        if visited[start][i] == 0 and computers[start][i] == 1:
            visited[start][i] = 1                                   # visited table have to be transpose matrix
            visited[i][start] = 1
            return DFS(computers, i, n)
                
    return 1

# Result: Accuracy 0% (100%)
