# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.0


def main():
    N = int(input())
    lst = []
    start=0
    end=0
    answer=0
    for i in range(N):
        lst.append(list(map(int, input().split(" "))))

    lst.sort()
    for i, meet in enumerate(lst):
        end=meet[1]
        count=1
        for j in range(i+1, N):
            if end <= lst[j][0]:
                count+=1
                end = lst[j][1]
        answer = max(answer, count)
    print(answer)


if __name__ == "__main__":
    main()

# Result: Time over
