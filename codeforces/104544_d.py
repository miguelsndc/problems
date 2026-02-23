from math import ceil
for _ in range(int(input())):
    x, y = map(int, input().split(' '))

    """
        b >= y/100 * (x + b)
        100b >= y * (x + b)
        100b >= yx + yb
        100b - yb >= yx
        b(100 - y) >= yx
        b == teto(yx/(100-y))
    """

    if y == 100:
        print(-1)
        continue
    k = ceil(x*y/(100-y)) 
    print(x + k)