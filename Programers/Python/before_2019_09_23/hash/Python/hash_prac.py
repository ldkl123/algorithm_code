
lst1 = ["a", "a", "b", "c"]
lst2 = ["a", "b", "c"]
dic={}
temp=0
for el in lst1:
    dic[hash(el)] = el
    temp += hash(el)
print(dic)
for el in lst2:
    temp -= hash(el)

answer = dic[temp]

print(temp)
print(answer)

