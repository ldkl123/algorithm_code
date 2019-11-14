# Developed by "DoKyu Lee"
# Date: 2019.10.10
# Version: 1.2

def main():
    N = int(input())
    prev_lo=[0,0]; ans=0; prev=0; rej=0
    part = list(map(int, input().split()))
    for i in range(1, N+1):
        if part[i-1] > prev_lo[1]:
            prev_lo[0] = prev_lo[1]
            prev_lo[1] = part[i-1]
            ans+=1
        elif part[i-1] < prev_lo[1] and part[i-1] > prev_lo[0]:
            prev_lo[1] = part[i-1]
        else:
            rej += 1
            if rej >= ans:
                prev_lo[0] = prev
                prev_lo[1] = part[i-1]
                ans = rej
            else:
                prev = part[i-1]
        #print("{}, {} {}".format(prev_lo, ans, rej))
    print(ans)

if __name__ == "__main__":
    main()