# Developed by "DoKyu Lee"
# Date: 2019.09.30
# Version: 2.0
# Using greedy algorithm

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
    
"ABAAAAAAABA": 6
"AAB": 2
"AABAAAAAAABBB": 12
"ZZZ": 5
"BBBBAAAAAB": 10
"BBBBAAAABA": 12
