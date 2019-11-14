#-*- coding:utf-8 -*-
import queue

q = queue.Queue()

lst = []
lst.append(1)
lst.append(2)

for val in lst:
    q.put(val)

print(q)

print(q.get())
print(q)
