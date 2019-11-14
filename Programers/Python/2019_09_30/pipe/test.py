def solution(arrangement):
    answer = 0
    stack = []
    pipe=0
    laser=False
    for ar in arrangement:
        if not stack:
            stack.append(ar)
            pipe+=1
        else:
            if ar is '(':
                if laser:
                    laser = False
                pipe+=1
                stack.append(ar)
            elif ar is ')':
                pipe-=1
                if laser:
                    answer+=1
                else:
                    laser=True
                    answer+=pipe
                stack.pop()             
    return answer
