# Developed by "DoKyu Lee"
# Date: 2019.10.02
# Version: 1.0


def main():
    num = input()
    num_lst = list(map(int, list(num))) 
    num = int(num)
    print(num_lst)
    answer=0
    if is_have_zero(num_lst):
        if is_three_mult(num_lst):
            num_lst.sort(reverse=True)
            num_lst = list(map(str, num_lst))
            answer = ''.join(num_lst)
        else:
            answer=-1
    else:
        answer=-1

    print(answer)

def is_have_zero(lst):
    for i in lst:
        if i is 0:
            return True
    return False

def is_three_mult(lst):
    s=0
    for i in lst:
        s+=i
    if s%3 is 0:
        return True
    else:
        return False

if __name__=="__main__":
    main()
