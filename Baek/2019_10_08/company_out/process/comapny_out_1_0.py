# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.0
import sys
def main():
    d = [0]*16
    N = int(input())
    for i in range(N):
        t, p = map(int, sys.stdin.readline().split())
        d[i+t] = max(d[i+t], d[i]+ p)
    print(max(d[0:N]))

if __name__ == "__main__":
    main()


# Result : runtime error