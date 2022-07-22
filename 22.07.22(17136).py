import math
import sys
input = sys.stdin.readline
answer = 100
paper = [5,5,5,5,5]
def poss(y, x, size):
    for i in range(size+1):
        for j in range(size+1):
            if board[y+i][x+j] == 0:
                return False
    return True
def attatch(y, x, size, value):
    for i in range(size+1):
        for j in range(size+1):
            board[y+i][x+j] = value
def rec(y, x, count):
    global answer
    global paper
    while board[y][x] == 0:
        x+=1
        if x==10:
            y+=1
            if y ==10:
                answer = min(answer, count)
                return
            x = 0
    if answer <= count:
        return
    for i in range(4, -1, -1):
        if y+i > 9 or x + i > 9 or paper[i] == 0:
            continue
        if poss(y,x,i):
            attatch(y,x,i,0)
            paper[i]-=1
            rec(y,x,count+1)
            attatch(y,x,i,1)
            paper[i]+=1
board = [list(map(int, input().split())) for i in range(10)]
rec(0,0,0)
if answer == 100:
    print(-1)
else:
    print(answer)