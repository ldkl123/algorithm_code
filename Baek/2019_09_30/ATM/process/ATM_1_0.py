# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.0

def main():
    N = int(input())
    p = list(map(int, input().split(" ")))
    p.sort()
    
    answer=0
    temp=0
    for _p in p:
        temp = temp +_p             # temp represent wait time
        answer += temp

    print(answer)


if __name__ == "__main__":
    main()

#Result: Correct
