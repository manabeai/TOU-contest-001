#!/usr/bin/env python3

import collections,sys,math,functools,operator,itertools,bisect,heapq,decimal,string,time,random
#sys.setrecursionlimit(10**9)
#sys.set_int_max_str_digits(0)
#input = sys.stdin.readline
#n = int(input())
#
#alist = []
#s = input()
n,m,k,x = map(int,input().split())
x -= 1
#for i in range(n):
#    alist.append(list(map(int,input().split())))

a = list(map(int,input().split()))
s = list(map(lambda x:int(x)-1,input().split()))

edge = [[] for i in range(n+1)]
for i in range(m):
    u,v = map(int,input().split())
    u-=1
    v-=1
    edge[u].append(v)

for i in s:
    edge[n].append(i)

start = n
d = []
dist = [10**18 for i in range(n+1)]
dist_res = [-1 for i in range(n+1)]
heapq.heappush(d,(0,n))
dist[n] = 0
while d:
    _,now = heapq.heappop(d)
    if _ > dist[now]:
        continue
    for to in edge[now]:
        cost = a[to]
        if dist[to] > dist[now] + cost:
            dist[to] = dist[now] + cost
            heapq.heappush(d,(dist[to],to))
            dist_res[to] = now

if dist[x] == 10**18:
    exit(print(-1))
ans = []
now = x
while now != -1:
    ans.append(now+1)
    now = dist_res[now]
ans.pop()
ans.reverse()
print(len(ans))
print(*ans)
