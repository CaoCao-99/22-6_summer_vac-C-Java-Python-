n,m = map(int, input().split())
array = list(map(int, input().split()))
low = max(array)
high = sum(array)
def check(k):
    mid2 = k
    count = 1
    for i in range(n):
        mid2 -= array[i]
        if mid2 < 0:
            count+=1
            mid2 = k - array[i]
    return count <= m

answer = 0

while low <= high:
    mid = (low + high) // 2
    if check(mid):
        high = mid -1
        answer = mid
    else:
        low = mid + 1
print(answer)
count = 0
mid2 = answer

for i in range(n):
    mid2 -= array[i]
    if mid2 < 0:
        print(count,end=' ')
        count = 0
        m-=1
        mid2 = answer - array[i]
    count+=1

    if n - i == m:
        print(count, end=' ')
        m-=1
        for j in range(m):
            print(1,end=' ')
