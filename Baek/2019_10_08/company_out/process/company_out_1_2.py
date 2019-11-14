# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.2
import sys
def main():
    d = [0]*16
    N = int(input())
    for i in range(N):
        t, p = map(int, sys.stdin.readline().split())
        if i+t-1 < 16:
            d[i+t-1] = max(d[i+t-1], d[i]+p)
    print(d)
    print(d[0:N+1])
    print(max(d[0:N+1]))

if __name__ == "__main__":
    main()