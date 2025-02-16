#!/usr/bin/python

import re
import sys

H_MIN = 1
H_MAX = 10

W_MIN = 1
W_MAX = 10

A_MIN = 0
A_MAX = 100


def main():
    m = re.match(r'^(\d+) (\d+)\n$', sys.stdin.readline())
    assert m, 'Does not match with regexp'
    H, W = map(int, m.groups())
    assert H_MIN <= H <= H_MAX, 'a out of range: %d' % H
    assert W_MIN <= W <= W_MAX, 'a out of range: %d' % W

    for i in range(H):
        m = re.match(r'^\d+(?:\s+\d+)*$', sys.stdin.readline())
        A = list(map(int, m.group().split()))
        assert len(A) == W, 'invalid length'
        for a in A:
            assert A_MIN <= a <= A_MAX, 'a out of range: %d' % a
    
    assert sys.stdin.read() == '', 'extra data'

if __name__ == '__main__':
    main()
