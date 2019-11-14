# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 2.0


def main():
    N = int(input())
    lst = []
    start=0
    end=0
    answer=1
    for i in range(N):
        s, e = map(int, input().split(" "))
        lst.append([e,s])

    lst.sort()
    end = lst[0][0]
    for meet in lst:
        if meet[1] >= end:
            end = meet[0]
            answer+=1
    print(answer)

if __name__ == "__main__":
    main()

# Result: Not correct
