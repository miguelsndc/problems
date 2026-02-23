p,q=map(float, input().split())
ans = 1e18
for i in range(1, 10000):
    for j in range(1, i):
        ratio = (j / i) * 100
        if (ratio > p and ratio < q):
            ans = min(ans, i);
print(ans)