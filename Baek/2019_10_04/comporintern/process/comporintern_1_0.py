# Developed by "DoKyu Lee"
# Date: 2019.10.07
# Version: 1.0


def main():
    N, M, K = map(int,input().split())
    total = N+M
    quit_team = int(K/3)
    quit_left = K%3
    team = min(int(N/2), M)
    st_left = total - 3*team
    answer =0

    answer = team - quit_team
    if quit_left > st_left:
        answer-=1

    print(answer)

    

if __name__ == "__main__":
    main()
