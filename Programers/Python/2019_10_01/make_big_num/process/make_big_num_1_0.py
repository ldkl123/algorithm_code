# Developed by "DoKyu Lee"
# Date: 2019.10.01
# Version: 1.0

def solution(number, k):
    answer = ''
    number = list(number)
    n = len(number)
    number.reverse()
    print(number)
    count=0
    while True:
        if number[-1] < number[-2]:             # Reverse the list of number and compare each element form tail to head
            number.pop()
        else:
            temp=number[-1]
            number.pop()
            number.pop()
            number.append(temp)
        count+=1
        print(number)
        if count is k:
            break
    number.reverse()
    answer = ''.join(number)
    print(answer)
    return answer
