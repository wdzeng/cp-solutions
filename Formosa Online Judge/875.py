from sys import stdin
from collections import deque
import re

# AC

t = int(input())
for i in range(t):
    q = deque()
    str = stdin.readline()
    list = re.findall('[+*]|\d+', str)
    for item in list:
        if item == '+':
            a = q.pop()
            b = q.pop()
            c = a + b
            q.append(c)
        elif item == '*':
            a = q.pop()
            b = q.pop()
            c = a * b
            q.append(c)
        else:
            q.append(int(item))
    print(q.pop())