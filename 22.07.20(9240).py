import math
import sys
input = sys.stdin.readline
c = int(input())
arr =[[0]* 2 for i in range(c)]
def CCW(x,y,z):
    return x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) + z[0] * (x[1] - y[1])
def dist(x,y):
    return math.sqrt((x[0] - y[0])*(x[0] - y[0]) + (x[1] - y[1])*(x[1] - y[1]))
def compare(x, y):
    ccw = CCW(arr[0],x,y)
    if ccw != 0:
        return ccw > 0
    elif x[0] != y[0]:
        return x[0] < y[0]
    else:
        return x[1] < y[1]
for i in range(c):
    arr[i][0], arr[i][1] = map(int, input().split())

for i in range(c):
    if arr[0][0] > arr[i][0]:
        arr[0],arr[i] = arr[i],arr[0]
    elif arr[0][0] == arr[i][0] and arr[0][1] > arr[i][1]:
        arr[0], arr[i] = arr[i], arr[0]
arr.sort(key = lambda x:x[1])
#arr = sorted(arr[1:], compare())
stack = list()
stack.append(arr[0])
stack.append(arr[1])
for i in range(2,c):
    while len(stack) > 2 and CCW(stack[len(stack)-2],stack[len(stack)-1], arr[i]) <=0:
        stack.pop()
    stack.append(arr[i])
j=1
answer = 0

for i in range(len(stack)):
    i_n = (i+1)%len(stack)
    while True:
        j_n = (j+1)%len(stack)
        b_y = stack[i_n][0] - stack[i][0]
        b_x = stack[i_n][1] - stack[i][1]
        c_y = stack[j_n][0] - stack[j][0]
        c_x = stack[j_n][1] - stack[j][1]
        root = [0, 0]
        fir = [b_x, b_y]
        sec = [c_x, c_y]
        if CCW(root, fir, sec) > 0:
            j = j_n
        else:
            break

    if answer < dist(arr[i], arr[j]):
        answer = dist(arr[i], arr[j])
print(answer)
