# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.0

import sys
import math

def main():
    word=[]
    N = int(input())
    for i in range(N):
        w = input()
        W = list(w)
        word.append([len(W)-1, w, W])

    word.sort()

    for i, (_,w,_) in enumerate(word):
        if i==0:
            print(w)
        else:
            if word[i-1][1] != w:
                print(w)
if __name__=="__main__":
    main()

# 'is' operation is comparing the reference of address. So judging True or False is recommended