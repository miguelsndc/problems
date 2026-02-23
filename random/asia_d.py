from math import sin, cos, atan, pi, sqrt
for _ in range(int(input())):   
    a, b, r, d = map(int, input().split(' '))
    phi = atan(b / (r + a))
    d_rad = d * (pi / 180.0)
    ans = 0
    if d_rad >= phi:
        ans = sqrt((r + a) ** 2 + b * b) - r
    else:
        ans = (r + a) * cos(d_rad) + b * sin(d_rad) - r
    print(f"{ans:.20f}")