# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 1.2

def solution(name):
    answer = 0
    name = list(name)
    for al in name:
        answer += alpha(al)
    
    answer += move(name)
    print(answer)
    return answer

# Counting changing alphabet joystick operation
def alpha(alphabet):
    al = ord(alphabet)
    if  al > ord('N'):                         # N is the middle of the alphabet
        return ord('Z') - al + +1              # If alphabet number is higher than 'N', using previous operation is more efficient
    elif al < ord('N'):
        return al - ord('A')
    else:
        return 13                             # If 'N', all way is available

# Counting moving joystick operation 
def move(name):
    n = len(name)
    flag=False
    start=0
    end=0
    for i, al in enumerate(name):
        if flag is False and al is 'A':
            flag = True
            start = i
        elif flag is True and al is not 'A':
            flag = False
            end = i
            break
    if end-start+1 is n:                     # If name is all 'A'
        return 0
    if start > n/2:                          # If 'A' starting point is small than half size of name, backward operation is more efficient
        return n-1
    else:
        return n-(end-start)-1 
