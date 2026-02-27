n, k=map(int,input().split(' '))
total=0
cnt =0
while total<k:
    total += n
    n += 1
    cnt+= 1
print(cnt - 1)