# Developed by "DoKyu Lee"
# Date: 2019.09.24
# Version: 1.0

visited=[]

def solution(n, computers):
    answer=0
    visited = [[0]*n for y in range(n)]
    
    for i in range(n):
        answer += dfs_recursive(visited, computers[i], i, i, n)
    print(answer)
    
    return answer

def dfs_recursive(visited, computers, i, place, n):
    print(visited)
    if i < n and place < n:
        if visited[i][place] == 0 and computers[place]:
            visited[i][place] = 1
            dfs_recursive(visited, computers,i, place+1, n)
        elif visited[i][place] == 0 and computers[place] == 0:
            visited[i][place] = 1
            return 1
    return 0
