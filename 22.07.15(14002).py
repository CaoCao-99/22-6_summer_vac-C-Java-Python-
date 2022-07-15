import sys
input = sys.stdin.readline
n = int(input())
dp = [1]*n
#dp = [1 for i in range(n)]
arr = list(map(int, input().split()))
for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+1)
print(max(dp))
answer = max(dp)
cnt = []
for i in range(n-1, -1, -1):
    if dp[i] == answer:
        answer-=1
        cnt.append(arr[i])
cnt.reverse()
for i in cnt:
    print(i, end=' ')