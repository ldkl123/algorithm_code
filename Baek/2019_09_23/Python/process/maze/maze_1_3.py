# Developed by "DoKyu Lee"
# Date: 2019.09.22
# Version: 1.3     

import queue

r, l = map(int, input().split(" "))
maze = []

        #up      down    left     right
move = [(0, 1), (0, -1), (-1, 0), (1, 0)]         # Added 'left' operation

# Making Queue for BFS
q = queue.Queue()

# Making a maze
for i in range(r):
    maze.append(list(map(int, list(input()))))

# Making visited history of map
visited = [[0]*l for i in range(r)]

x, y =[0, 0]
move_lst = []

# BFS function using move operation to search the way which is the shortest path
def BFS(x, y, c):
    
    q.put([x, y, c])
    visited[y][x] = 1       # x coordinate have to be col, and y is row
    while q.qsize():
        x, y, c = q.get()        
        for dx, dy in move:
            nx = x+dx
            ny = y+dy
            if nx >= 0 and nx < l and ny >= 0 and ny < r:
                if nx == l-1 and ny == r-1:
                    nc = c+1
                    move_lst.append(nc)
                elif visited[ny][nx] == 0 and maze[ny][nx] == 1:
                    nc = c+1                               # Using c+=1 is incorrect because in 4 moving operation have to use "c" which is added +1. c+=1 increases the number while seraching four way moving.   
                    q.put([nx, ny, nc])
                    visited[ny][nx] = 1
# main: Using BFS and find shortest way
def main():
    BFS(0,0,1)
    print(min(move_lst))	

if __name__ == "__main__":
    main()

#Result : 15
    
