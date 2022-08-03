import math
import sys
from collections import deque
input = sys.stdin.readline
c_cnt, p_cnt = 0,0
n, m = map(int,input().split())
arr = [[0] * 50 for i in range(50)]
car = [[0] * 2 for i in range(100)]
park = [[0] * 2 for i in range(100)]
dist = [[0]*100 for i in range(100)]
dy = [-1,1,0,1]
dx = [0,0,-1,1]
v = {}


def DFS(car_num, time):
    for next in v[car_num]:
        if check[next] == True or dist[car_num][next] > time:continue
        check[next] = True
        if used[next] == -1 or DFS(used[next], time):
            used[next] = car_num
            return True
    return False


def BFS(car_num):
    q = []
    visit = [[-1] * 50 for i in range(50)]
    q.append(([car_num][0], car[car_num][1]))
    visit[car[car_num][0]][car[car_num][1]] = 0
    while q:
        a = q.pop(0)
        hy = a[0]
        hx = a[1]
        for i in range(4):
            ny, nx = hy + dy[i], hx + dx[i]
            if ny <0 or nx <0 or ny >=n or nx >= m or visit[ny][nx] != -1 or arr[ny][nx] =='X':continue
            visit[ny][nx] = visit[hy][hx] + 1
            q.append((ny,nx))
    for i in range(p_cnt):
        if visit[park[i][0]][park[i][1]] == -1:
            dist[car_num][i] = 999999999
        else:
            dist[car_num][i] = visit[park[i][0]][park[i][1]]
            v[car_num].append(i)

for i in range(100):
    v[i] = []

for i in range(n):
    s = input()
    for j in range(m):
        arr[i][j] = s[j]
        if s[j] == 'C':
            car[c_cnt][0] = i
            car[c_cnt][1] = j
            c_cnt+=1
        if s[j] == 'P':
            park[p_cnt][0] = i
            park[p_cnt][1] = j
            p_cnt+=1

for i in range(c_cnt):
    BFS(i)
answer = -1
s = 0
e = 50 *50
while s <= e:
    mid = (s+e)//2
    ret = 0
    used = [-1] * 100
    for i in range(c_cnt):
        check = [False] * 100
        if DFS(i, mid):
            ret+=1
    if ret == c_cnt:
        answer = mid
        e = mid -1
    else:
        s = mid +1
print(answer)

