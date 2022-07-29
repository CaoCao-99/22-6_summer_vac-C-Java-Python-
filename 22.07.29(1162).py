import heapq
import math
import sys
from collections import deque
input = sys.stdin.readline
INF = sys.maxsize
n,m,k = map(int, input().split())
dp = [[INF] * (k+1) for i in range(n+1)]
adj = [[] for i in range(n+1)]
for i in range(m):
    x,y,z = map(int, input().split())
    adj[x].append((z,y))
    adj[y].append((z,x))
def BFS():
    queue = []
    dp[1][0] = 0
    heapq.heappush(queue, (0, 1, 0))#가중치, 도시 번호, 포장도로 수
    while queue:
        w, n, c = heapq.heappop(queue)
        if dp[n][c] < w:continue
        for a, b in adj[n]:
            next_w = a + w
            if dp[b][c] > next_w:
                dp[b][c] = next_w
                heapq.heappush(queue, (next_w, b, c))
            if c < k and dp[b][c+1] > w:
                dp[b][c+1] = w
                heapq.heappush(queue, (w, b, c+1))
BFS()
print(min(dp[n]))