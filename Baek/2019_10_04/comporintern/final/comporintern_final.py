# Developed by "DoKyu Lee"
# Date: 2019.10.07
# Version: 1.1

import math

def main():
    N, M, K = map(int,input().split())
    total = N+M
    team = min(int(N/2), M)
    st_left = total - 3*team
    answer =0

    
    if K > st_left:
        K-=st_left
        answer = team-math.ceil(K/3)
    else:
        answer = team

    print(answer)

    

if __name__ == "__main__":
    main()
