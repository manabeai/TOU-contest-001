#!/usr/bin/python

import re
import sys

H_MAX = 10 ** 6
H_MIN = 1

N_MAX = 10 ** 6
N_MIN = 1

A_MAX = 10 ** 18

def main():
    m = re.match(r'^(\d+) (\d+)\n$', sys.stdin.readline())
    assert m, 'Does not match with regexp'
    H, N = map(int, m.groups())
    assert H_MIN <= H <= H_MAX, 'H out of range: %d' % H
    assert N_MIN <= N <= N_MAX, 'N out of range: %d' % N

    A = list(map(int,input().split()))
    A_MIN = H
    assert len(A) == N, 'N and length of A are different'

    set_A = set()
    for a in A:
        assert A_MIN <= a <= A_MAX, 'a out of range: %d' % a
        assert a not in set_A, 'a is duplicated: %d' % a
        set_A.add(a)

if __name__ == '__main__':
    main()
