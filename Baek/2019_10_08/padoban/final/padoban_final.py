# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.0


def main():
    d=[1,1,1,2,2]
    T = int(input())
    for i in range(T):
        N = int(input())
        for i in range(N):
            if i >= len(d):
                d.append(d[i-1] + d[i-5])
        print(d[N-1])
if __name__ == "__main__":
    main()