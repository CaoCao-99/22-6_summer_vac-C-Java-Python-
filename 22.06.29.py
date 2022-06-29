cnt = 0
real_prime = [0]*170000

prime = [True]*1000000

for i in range(2,int(len(prime)**(1/2))):
    if(prime[i] == False):continue
    for j in range(i*i, 1000000, i):
        prime[j]=False
for i in range(2,len(prime)):
    if(prime[i] == True):
        real_prime[cnt] = i
        cnt+=1
#N값 입력
N = int(input())
#N개의 값 입력
input2 = list(map(int, input().split()))
prime_input = [[0]*170000 for j in range(N)]
prime_count = [0]*170000
for i in range(N):
    for j in range(cnt):
        if real_prime[j]!=0:
            while input2[i] % real_prime[j] == 0:
                input2[i]/=real_prime[j]
                prime_input[i][j]+=1
                prime_count[j]+=1
answer=1
count = 0
for i in range(cnt):
    prime_count[i]/=N
for i in range(len(prime_count)):
    if prime_count[i] >= 1:
        answer *= real_prime[i] ** prime_count[i]
for i in range(N):
    for j in range(cnt):
        if int(prime_input[i][j] - prime_count[j]) < 0:
            count+=int(prime_count[j] - prime_input[i][j])
print(int(answer), int(count))

