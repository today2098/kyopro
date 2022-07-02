n, x = map(int, input().split())
x -= 1

ans = chr(ord('A')+x//n)
print(ans)
