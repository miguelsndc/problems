n = int(input())
l = [''] * n; mx = 0
for i in range(n):
    l[i] = input()
    mx = max(mx, len(l[i]))

for i in l:
    q = (mx - len(i)) // 2
    print (f"{'.' * q}{i}{'.' * q}")