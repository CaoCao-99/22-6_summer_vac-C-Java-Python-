
n = int(input())
answer = [[' ']*2*n for i in range(n)]


def draw(center, height, length):
    if length == 3:
        answer[height][center] = '*'
        answer[height+1][center-1] = answer[height+1][center+1] = '*'
        for i in range(-2, 3):
            answer[height+2][center+i] = '*'
        return
    len2 = int(length/2)
    draw(center, height, len2)
    draw(center - len2, height + len2, len2)
    draw(center + len2, height + len2, len2)
draw(n-1, 0, n)
for i in answer:
    print("".join(i))