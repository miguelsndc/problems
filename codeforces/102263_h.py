n, k = map(int, input().split(' '))
print (max((n + k - 1) // k * 5, 10))