import queue


N,V,F = map(int, input().split(" "))
visited = [0 for x in range(N)]
table =[[0]*(N) for y in range(N)]
q = queue.Queue()

for i in range(V):
    u,v = map(int,input().split(" "))
    table[u-1][v-1] = 1
    table[v-1][u-1] = 1

def DFS(start):
    visited[start-1] = 1

    print(start, end=" ")

    for i in range(N):
        if visited[i] == 0 and table[start-1][i] == 1:
            DFS(i+1)
    
def BFS(start):
    #visited[start-1] = 1
    q = queue.Queue()
    q.put(start-1)
    visited[start-1] = 1
    while q.qsize():
        n = q.get()
        print(n+1, end=" ")
        for i in range(N):
            if visited[i] == 0 and table[n][i] == 1:
                q.put(i)
                visited[i] = 1

def main():
    DFS(F)
    print()
    for i in range(N):
        visited[i] = 0
    BFS(F)
def show_table(table):    
    for row in table:
        print(row)

if __name__ == "__main__":
    main()
