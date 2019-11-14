# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.1
import sys
def main():
    d = [0]*16
    N = int(input())
    for i in range(N):
        t, p = map(int, sys.stdin.readline().split())
        if i+t < 16:
            temp=0
            if i is not 0:
                temp = max(d[0:i])
            d[i+t] = max(d[i+t], temp+p)
            d[i+t] = max(d[i+t], d[i]+p)

    print(max(d[0:N+1]))

if __name__ == "__main__":
    main()