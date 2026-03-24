import sys
def solve():
    n = int(input())
    for i in range(1, 2 * n, 2):
        print(f"? {i} {i + 1}")
        sys.stdout.flush()
        ans = int(input())
        if ans == 1:
            print(f"! {i}")
            sys.stdout.flush()
            return
        elif ans == -1:
            exit()
        print(f"? 1 3")
        sys.stdout.flush()
        ans = int(input())
        if ans == 1:
            print(f"! 1")
            sys.stdout.flush()
            return
        elif ans == 0:
            print(f"! 2")
            sys.stdout.flush()
            return
        else:
            exit()
        
        

for _ in range(int(input())):
    solve()