n = int(input())
z = list()
kind = list()
cnt = 0
answer = [0 for i in range(500001)]
cost = [0 for i in range(10001)]
p = [True for i in range(500001)]
for i in range(2, int(500000**0.5), 1):
    if not p[i]:
        continue
    for j in range(i*i, 500001, i):
        p[j] = False

z_cnt = 1

for i in range(n):
    z.append(int(input()))
    cost[z[i]]+=1
    if z[i] == 0:
        z_cnt+=1
kind2 = set(z)
kind = list(kind2)
answer[0]=1
for i in range(len(kind)):
    for j in range(500000, 0 , -1):
        for s in range(1, cost[kind[i]]+1, 1):
            if j >= s * kind[i]:
                answer[j] += answer[j - s * kind[i]]
ans = 0
for i in range(2,500001,1):
    if(p[i] and answer[i] >0):
       ans += answer[i]

print(ans * z_cnt)