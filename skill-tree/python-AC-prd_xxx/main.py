#!/usr/bin/env python3

import sys
input = sys.stdin.readline
N,M,K,X = map(int,input().split())
A = list(map(int,input().split()))
S = list(map(int,input().split()))
UV = [tuple(map(int,input().split())) for _ in range(M)]
rs = [[] for _ in range(N)]
for u,v in UV:
    rs[v-1].append(u-1)

import heapq
INF = 10**18
dist = [INF]*N
dist[X-1] = 0
hq = [(0,X-1)]
prev = [-1]*N
while hq:
    d,v = heapq.heappop(hq)
    if dist[v] < d:
        continue
    for u in rs[v]:
        if dist[u] > d + A[u]:
            dist[u] = d + A[u]
            heapq.heappush(hq,(dist[u],u))
            prev[u] = v

max_d = INF
max_i = -1
for s in S:
    s -= 1
    if dist[s] < max_d:
        max_d = dist[s]
        max_i = s
if max_d == INF:
    exit(print(-1))

ans = [max_i]
i = max_i
while prev[ans[-1]] != -1:
    ans.append(prev[i])
    i = prev[i]

assert (ans[0]+1) in S
assert ans[-1]+1 == X

print(len(ans))
print(*[a+1 for a in ans])
