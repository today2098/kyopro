n = int(input())

a = [[0]*i for i in range(1, n+1)]
for i in range(n):
    for j in range(i+1):
        if j == 0 or j == i:
            a[i][j] = 1
        else:
            a[i][j] = a[i-1][j-1]+a[i-1][j]

for out in a:
    print(*out)
