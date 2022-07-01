
def DFS(root, cnt):
    global nodeIdx
    if data[root][0] != -1:
        DFS(data[root][0],cnt + 1)
    low[cnt] = min(low[cnt], nodeIdx)
    high[cnt] = max(high[cnt], nodeIdx)
    answer[cnt] = high[cnt] - low[cnt]
    nodeIdx+=1
    if data[root][1] != -1:
        DFS(data[root][1], cnt+1)
n = int(input())
data = [[0]*2 for i in range(n+1)]
low = [10001 for i in range(n+1)]
high = [0 for i in range(n+1)]
answer = [0 for i in range(n+1)]
node = [0 for i in range(n+1)]
nodeIdx=1
for i in range(n):
    a,b,c = map(int, input().split())
    data[a][0] = b
    data[a][1] = c
    node[a]+=1
    if b!=-1:
        node[b]+=1
    if c!=-1:
        node[c]+=1
for i in range(n):
    if node[i] == 1:
        root = i
        break
answer1 = 1
answer_cnt = 1
DFS(root, 1)
for i in range(1, n+1):
    if answer1 < answer[i]:
        answer1 = answer[i]
        answer_cnt = i

print(answer_cnt, answer1)
