N, K, Q = map(int, input().split())
A = list(map(int, input().split()))
L = list(map(int, input().split()))

for i in range(Q):
    l = L[i]-1
    if l == K-1:
        if A[l] < N:
            A[l] += 1
    else:
        if A[l]+1 < A[l+1]:
            A[l] += 1

print(*A)
