import sys

R = lambda:map(int, sys.stdin.readline().rstrip().split())

def solve():
    n, m = R()
    lstA = list(R())
    lstB = list(R())

    for el in lstB:
        l = -1
        r = 1
        while r < n and lstA[r] < el:
            r *= 2
        if r >= n:
            if (lstA[n-1] < el):
                print(n, end=' ')
                continue
            r = n
        while r - l > 1:
            mid = (r + l) // 2
            if lstA[mid] < el:
                l = mid
            else:
                r = mid
        print(r, end=' ')

solve()
