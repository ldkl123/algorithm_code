# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.0

import sys
import math

def main():
    r, c = map(int, sys.stdin.readline().split())
    br=[]; ar=[]
    idx=0; answer=0
    for i in range(r):
        br.append(list(input()))
    for i in range(r):
        ar.append(list(input()))
    if r < 3 or c < 3:
        answer=-1
    else:
        while True:
            idx=0
            print_m(br)
            print()
            for i, (b, a) in enumerate(zip(br, ar)):
                if idx <= c-3 and i <= r-3:
                    if b[idx] is not a[idx]:
                        before = change(b, i, idx)
                        answer+=1
                    if _check(br, ar):
                        break
                    else:
                        idx+=1
            if idx is c-3:
                break
    if _check(br, ar):
        print(answer)
    else:
        print(-1)
def change(mat, r, c):
    temp = mat[r:r+3][c:c+3]
    for row in temp:
        for val in row:
            if val is 1:
                val = 0
            else:
                val = 1
    return mat

def _check(br, ar):
    for b, c in zip(br, ar):
        for bc, rc in zip(b, c):
            if bc is not rc:
                return False
    return True

def print_m(mat):
    for i in mat:
        print(i)

if __name__=="__main__":
    main()