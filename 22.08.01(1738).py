import math
import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int, input().split())
arr = [[] for i in range(n+1)]
rev = [[] for i in range(n+1)]
visit = [False] * (n+1)
pred = [0] * (n+1)
cost = [-99999999] * (n+1)
for i in range(m):
    a,b,c = map(int, input().split())
    arr[a].append((b,c))
    rev[b].append(a)
q = []
q.append(n)
visit[n] =True
cost[1] = 0

def answer(a):
    if a == 1:
        print(a,end=' ')
        return
    answer(pred[a])
    print(a, end=' ')

while q:
    next = q.pop(0)
    for i in rev[next]:
        if visit[i] == False:
            visit[i] = True
            q.append(next)

for i in range(1, n+1):
    for j in range(1, n+1):
        for c,d in arr[j]:
            if cost[j] != -99999999 and cost[c] < cost[j] + d:
                cost[c] = cost[j] + d;
                pred[c] = j
                if i == n and visit[c] == True:
                    print(-1)
                    exit(0)
answer(n)