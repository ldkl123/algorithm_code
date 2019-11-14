def solution(numbers, target):
    st = [0]
    answer = dfs_stack(st, numbers, target)
    return answer


def dfs_stack(st, numbers, target):
    answer=0
    curr_size=0
    size = len(numbers)
    temp=0
    idx=0
    while len(st) > 0:

        if curr_size < size:
            if target <= temp:
                temp-=2*numbers[idx]
                st.pop()
            elif target > temp:
                idx+=1
                st.append(-1*numbers[idx])                
                temp+=numbers[idx]
                curr_size+=1
        elif curr_size == size:
            if target == temp:
                answer+=1
            temp-=2*numbers[idx]
            st.pop()
        print(st)
        print("temp: "+str(temp))
        print("curr_size: "+str(curr_size))
        print("answer: "+str(answer))
    return answer

numbers = [1, 1, 1, 1, 1]
target = 3
solution(numbers, target)
