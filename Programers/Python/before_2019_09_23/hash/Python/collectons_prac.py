import collections

lst1 = ["a", "a", "b", "c"]
lst2 = ["a", "b", "c"]
container1 = collections.Counter(lst1)
container2 = collections.Counter(lst2)

print(container1)		
print(container2)

new_container = container2 - container1
print(new_container)
