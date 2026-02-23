import sys
try:
    sys.set_int_max_str_digits(5000000)
except:
    pass
for _ in range(int(input())):
    k = int(input())
    if (k <= 10):
        print(k - 1)
        continue

    d = len(str(k))
    P = max(0, d - 2)
    if P > 0:
        skip = 2 * (10 ** P) - 1
        if k > skip:
            k -= skip
            L = 2 * P + 1
        else:
            L = 1
    else: 
        L = 1

    while True:
        if L == 1:
            count = 10
        else:
            metade = (L + 1) // 2
            count = 9 * (10 ** (metade - 1))
        if k <= count:
           break
        k -= count
        L += 1        
    
    if L == 1:
        print(k - 1)
    else:
        metade_len = (L + 1) // 2
        base_val = 10 ** (metade_len - 1)
        val_metade = base_val + (k - 1)
        s = str(val_metade)   
        if L % 2 == 0:
            print(s + s[::-1])
        else:
            print(s + s[:-1][::-1])


