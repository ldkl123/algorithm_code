# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.1

import sys
import math

def main():
    r, c = map(int, sys.stdin.readline().split())
    br=[]; ar=[]
    idx=0; answer=0; flag=True
    for i in range(r):
        br.append(list(input()))
    for i in range(r):
        ar.append(list(input()))
    if r < 3 or c < 3:
        answer=-1
    else:
        while flag:
            print("idx: {}".format(idx) )
            print_m(br)
            print_m(ar)
            for i, (b, a) in enumerate(zip(br, ar)):
                if idx <= c-3 and i <= r-3:
                    if b[idx] is not a[idx]:
                        br = change(br, i, idx)
                        answer+=1
                    if _check(br, ar):
                        flag=False
                    else:
                        idx+=1
            if idx is c-2:
                break
    if _check(br, ar):
        print(answer)
    else:
        print(-1)
def change(mat, r, c):
    for i in range(r, r+3):
        for j in range(c, c+3):
            if mat[i][j] is '1':
                mat[i][j] = '0'
            elif mat[i][j] is '0':
                mat[i][j] = '1'
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
    print()

if __name__=="__main__":
    main()