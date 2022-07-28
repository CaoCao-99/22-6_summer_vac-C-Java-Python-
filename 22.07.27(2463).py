import math
import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int,input().split())
parent = [i for i in range(n+1)]
size = [1] * (n+1)
sum = 0
answer = 0
grap = [[0] * 3 for i in range(m)]
def get(a):
    if parent[a] == a:
        return a
    return get(parent[a])
def mergeP(a,b):
    if size[a] > size[b]:
        parent[b] = a
        size[a]  += size[b]
        size[b] = 1
    else:
        parent[a] = b
        size[b] += size[a]
        size[a] = 1

for i in range(m):
    a,b,c = map(int, input().split())
    grap[i] = [a,b,c]
    sum += c
grap.sort(key = lambda x: x[2], reverse=True)
for i in range(m):
    a = get(grap[i][0])
    b = get(grap[i][1])
    if a != b:
        answer += (((size[a] * size[b]) %1000000000) * sum) % 1000000000
        mergeP(a,b)
    sum -= grap[i][2]
print(answer%1000000000)