# Developed by "DoKyu Lee"
# Date: 2019.09.24
# Version: 2.6

visited=[]

def solution(n, computers):
    global visited               # visited have to be global variable
    answer=0
    visited = [0]*n         # visited history matrix, changed to 1 dimension
    
    for i in range(n):
        answer += DFS(computers, i, n)     # counting network number
        
    return answer

# Depth First Search: find conected network
def DFS(computers, start, n):
    if visited[start]:
        return 0
    else:
        for i in range(n):                      # get rid of visited[start][start]
            if visited[i] == 0 and computers[start][i] == 1:
                visited[i] = 1                                   # visited table have to be transpose matrix
                return DFS(computers, i, n)

    return 1

# Result: Accuracy 0% (100%)
