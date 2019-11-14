# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.0 


def main():
    N, K = map(int, input().split(" "))
    W = []
    idx = 0
    flag = False
    answer = 0
    for i in range(N):
        num = int(input())
        if flag is False and num > K:
            flag = True
            idx = i-1
        W.append(num)

    while K>0:
        if K >= W[idx]:
            K-= W[idx]
            answer+=1
        else:
            idx-=1
    print(answer)

if __name__ == "__main__":
    main()

#Reuslt: Time over
