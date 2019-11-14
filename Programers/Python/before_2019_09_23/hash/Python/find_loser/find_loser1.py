############################
# Developed by "DoKyu Lee" #
# Date: 2019.09.20         #
# Accuracy: 30%            #
# Effeciency: 0%           #
# Total: 0&                #
############################
#시간 복잡도를 고려하지 않았다. O(n^2)
#런타임 에러 2개
def solution(participant, completion):
    for win in completion:
        for i, player in enumerate(participant):
            if player == win:
                del participant[i]
    answer = participant[0]
    return answer
