#!/usr/bin/python
a = input()
b = input()
n = int(input())
S = []
for i in range(n):
    s = input()
    S.append(s)

print(abs(S.index(a)-S.index(b))-1)