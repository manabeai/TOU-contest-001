#!/usr/bin/python
d = int(input())
A,Y = map(int,input().split())
if A >= d and Y < d:
    print("Winner")
elif A < d and Y >= d:
    print("Loser")
else:
    print("Draw")