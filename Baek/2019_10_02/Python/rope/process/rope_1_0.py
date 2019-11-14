# Developed by "DoKyu Lee"
# Date: 2019.10.02
# Version: 1.0


def main():
    N = int(input())
    rope=[]

    for i in range(N):
        rope.append(int(input()))
    rope.sort()
    for i, w in enumerate(rope):
        rope[i] = N*rope[i]
        N-=1
    print(max(rope))

if __name__ =="__main__":
    main()
