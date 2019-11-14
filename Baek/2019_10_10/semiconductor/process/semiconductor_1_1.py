# Developed by "DoKyu Lee"
# Date: 2019.10.10
# Version: 1.1

def main():
    N = int(input())
    prev_lo=[0,0]; ans=0
    part = list(map(int, input().split()))
    for i in range(1, N+1):
        sub = abs(i-part[i-1])
        if part[i-1] > prev_lo[1]:
            prev_lo[0] = prev_lo[1]
            prev_lo[1] = part[i-1]
            ans+=1
        elif part[i-1] < prev_lo[1] and part[i-1] > prev_lo[0]:
            prev_lo[1] = part[i-1]
    print(ans)

if __name__ == "__main__":
    main()

# 5, 4 5 1 2 3 failed