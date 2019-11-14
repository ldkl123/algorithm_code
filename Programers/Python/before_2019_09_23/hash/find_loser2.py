############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.20         #
# Accuracy: 50%            #
# Effeciency: 50%          #
# Total: 100&              #
############################


# list의 sort 사용
def solution(participant, completion):
    answer=''
    find=False
    participant.sort()
    completion.sort()
    for i, name in enumerate(completion):
        if participant[i] != name:
            answer = participant[i]
            find=True
            break

    if find==False:
        answer = participant[-1]       #만약 마지막에 선수가 없을 수도 있으므로 예외처리

    return answer

