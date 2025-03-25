#!/usr/bin/python
N,k = map(int,input().split())
S = input()

ans = 0
con = 1
for i in range(1,N):
    if S[i-1] == S[i] and con == k - 1:
        con = 0
        ans += 1
    elif S[i-1] == S[i]:
        con += 1
    else:
        con = 1

print(ans)