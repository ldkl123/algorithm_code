# Developed by "DoKyu Lee"
# Date: 2019.09.22
# Version: 1.0     

import queue

r, l = map(int, input().split(" "))
maze = []
visited = [[0]*l for i in range(r)]
      #up      down    right
move = [(0, 1), (0, -1), (1, 0)]
q = queue.Queue()
for i in range(r):
    maze.append(list(map(int, list(input()))))
  
x, y =[0, 0]
move_lst = []
print(maze)
print(visited)

def BFS(x, y, c):
    
    q.put([x, y, c])
    visited[x][y] = 1
    while q.qsize():
        x, y, c = q.get()
        print(list(q.queue))
        print(q.qsize())
        for dx, dy in move:
            nx = x+dx
            ny = y+dy
            c+=1
            print([nx, ny])
            if nx >= 0 and nx < l and ny >= 0 and ny < r:
                if nx == l-1 and ny == r-1:
                    move_lst.append(c)
                elif visited[ny][nx] == 0 and maze[ny][nx] == 1:
                    q.put([nx, ny, c])
                    visited[ny][nx] = 1
def main():
    BFS(0,0,0)
    print(move_lst)

if __name__ == "__main__":
    main()
    
