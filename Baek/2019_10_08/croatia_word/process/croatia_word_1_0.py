# Developed by "DoKyu Lee"
# Date: 2019.10.08
# Version: 1.0

import sys
import math

def main():
    answer=0
    sen = list(input())
    print(sen)
    c_g=False; d_g=False; z_g=False; ln_g=False; sz_g=False
    for w in sen:

        if c_g:
            if w =='=' or w =='-':
                answer-=1
            c_g=False
        if d_g:
            if z_g:
                if w=='=':
                    answer-=2
                z_g=False
            else:
                if w=='-':
                    answer-=1
                d_g=False
            if w=='z':
                z_g=True
        if ln_g:
            if w=='j':
                answer-=1
            ln_g=False
        if sz_g:
            if w=='=':
                answer-=1
            sz_g=False
        answer+=1
        if w == 'c': c_g=True
        if w == 'd': d_g=True
        if w == 'l' or w == 'n': ln_g=True
        if w == 's' or w == 'z': sz_g=True
        print("{},{}".format(w, answer))
    print(answer)
if __name__=="__main__":
    main()