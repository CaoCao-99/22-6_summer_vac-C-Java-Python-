import math
import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int,input().split())
visit = [[False] * m for i in range(n)]
dir = [(0,-1), (1, 0), (0, 1), (-1, 0)]
zeros = [[0] * m for i in range(n)]
ccnntt = {}
idx  =  1
board = [list(map(int, input().strip())) for i in range(n)]
def BFS(y, x):
    q = deque()
    visit[y][x] = True
    q.append([y, x])
    cnt = 1
    while q:
        h_y, h_x = q.pop()
        zeros[h_y][h_x] = idx
        for i, j in dir:
            n_y, n_x = h_y + i, h_x + j
            if n_y < 0 or n_x < 0 or n_x >= m or n_y >= n or visit[n_y][n_x] == True or board[n_y][n_x] != 0:continue
            cnt+=1
            visit[n_y][n_x] = True
            q.append([n_y, n_x])
    return cnt
def find(y, x):
    s = set()
    cnt = 1
    for i, j in dir:
        n_y, n_x = y + i, x + j
        if n_y < 0 or n_x < 0 or n_x >= m or n_y >= n or not zeros[n_y][n_x]:continue
        s.add(zeros[n_y][n_x])
    #print(s)
    for i in s:
        cnt += ccnntt[i]
    return cnt%10



for i in range(n):
    for j in range(m):
        if visit[i][j] == False and board[i][j] == 0:
            k = BFS(i, j)
            ccnntt[idx] = k
            idx+=1
answer = [[0] * m for i in range(n)]
for i in range(n):
    for j in range(m):
        if board[i][j]:
            answer[i][j] = find(i,j)
for i in range(n):
    for j in answer[i]:
        print(j ,end='')
    print()