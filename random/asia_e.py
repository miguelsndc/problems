from math import gcd
maxn = 1000
crivo = [1] * maxn
next = [1] * maxn
crivo[0] = crivo[1] = False
for i in range(2, maxn):
    if crivo[i]:
        for j in range(2 * i, maxn, i):
            crivo[j] = False
prox = -1
for i in range(maxn - 1, -1, -1):
    next[i] = prox
    if (crivo[i]):
        prox = i

for _ in range(int(input())):
    k = int(input())
    prod = 1; sum = 1; cur = 1
    real_prod = 1
    while next[cur] != -1 and real_prod * next[cur] <= k:
        cur = next[cur]
        real_prod *= cur
        prod *= cur
        sum = sum + sum * cur
        g = gcd(prod, sum)
        sum //= g
        prod //= g
        
    print(f"{prod}/{sum}")