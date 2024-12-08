#!/usr/bin/python

import sys


def main():
    a, b = map(int, sys.stdin.read().strip().split())
    ans = 0
    for i in range(a):
        ans += 1

    for i in range(b):
        ans += 1

    print(ans)


if __name__ == '__main__':
    main()
