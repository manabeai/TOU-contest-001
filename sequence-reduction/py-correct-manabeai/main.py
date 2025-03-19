#!/usr/bin/python

from collections import deque

n,m = map(int,input().split())
C = list(map(str,input().split()))

stack = deque()

for i in range(n):
    if len(stack) == 0:
        stack.append((C[i],1))
    elif stack[-1][0] == C[i]:
        stack.append((C[i],stack[-1][1]+1))
    else:
        stack.append((C[i],1))

    if stack[-1][1] == m:
        while len(stack) != 0 and stack[-1][0] == C[i]:
            stack.pop()

print(len(stack))