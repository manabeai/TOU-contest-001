#!/usr/bin/python
def tousa(a, n, d):
    return (n * (2 * a + (n - 1) * d)) // 2

def solve():
    h, n = map(int, input().split())
    A = sorted(list(map(int, input().split())))
    

    ans = tousa(1, h, 2) * n

    for i in range(1, n):
        dist = A[i] - A[i - 1]

        if dist < h * 2 - 1:
            if dist % 2 == 1:
                ans -= tousa(2, h - (dist + 1) // 2, 2)
            else:
                ans -= tousa(1, h - dist // 2, 2)

    print(ans)

if __name__ == "__main__":
    solve()
