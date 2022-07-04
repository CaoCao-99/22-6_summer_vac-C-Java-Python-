
def recursive(y, x, size):
    isone = True
    iszero = True
    if size == 1:
        print(input2[y][x], end = '')
        return
    for i in range(size):
        for j in range(size):
            if input2[y+i][x+j] == '0':
                isone = False
            if input2[y+i][x+j] == '1':
                iszero = False
    if iszero:
        print('0', end='')
        return
    if isone:
        print('1', end='')
        return
    print('(', end='')
    resize = size // 2
    recursive(y,x,resize)
    recursive(y,x+resize, resize)
    recursive(y+resize, x, resize)
    recursive(y+resize, x+resize, resize)
    print(')',end='')

n = int(input())
input2 = [['']*(n+1) for i in range(n+1)]

for i in range(n):
    input2[i] = input()
recursive(0,0,n)
