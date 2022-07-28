import math
import sys
from collections import deque
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, m, s ,t = map(int,input().split())
st = []#stack
adj = [[] for i in range(n+1)]
scc = list([] for i in range(n+1))
discover = [-1] * (n+1)
sccn = [-1] * (n+1)
country = [0] * (n+1)
answer = [0] * (n+1)
scnt = 1
start, target = 0,0
cnt = 0
def BFS(start):
    answer[start] = country[start]
    q = []
    q.append(start)
    while q:
        now = q.pop(0)
        for i in scc[now]:
            if answer[i] < answer[now] + country[i]:
                answer[i] = answer[now] + country[i]
                q.append(i)

def DFS(x):
    global scnt,cnt, start, target
    st.append(x)
    discover[x] = cnt
    cnt+=1
    parent = discover[x]
    for i in adj[x]:
        if discover[i] == -1:
            parent = min(parent, DFS(i))
        elif sccn[i] == -1:
            parent = min(parent, discover[i])
    if parent == discover[x]:
        while 1:
            here = st.pop()
            sccn[here] = scnt
            country[scnt]+=1
            if s == here:start = scnt
            if t == here:target = scnt
            if here == x:break
        scnt+=1
    return parent
for i in range(1, m+1):
    a,b = map(int , input().split())
    adj[a].append(b)
for i in range(1, n+1):
    if discover[i] == -1:
        DFS(i)
if start == target:
    print(country[start])
else:
    for i in range(1, n+1):
        for j in adj[i]:
            next = sccn[j]
            if sccn[i] != next:
                scc[sccn[i]].append(next)
    BFS(start)
    print(answer[target])