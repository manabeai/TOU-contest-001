#!/usr/bin/python

import re
import sys

N_MIN = 3
N_MAX = 10 ** 5

k_MIN = 3
k_MAX = N_MAX

def main():
    
    m = re.match(r'^(\d+) (\d+)\n$', sys.stdin.readline())
    s = re.match(r'^[AB]{3,}$', sys.stdin.readline())
    assert m, 'Does not match with regexp'
    N,k = map(int, m.groups())
    S = s.group()
    assert N_MIN <= N <= N_MAX, 'a out of range: %d' % N
    assert k_MIN <= k <= k_MAX, 'a out of range: %d' % k

    assert len(S) == N, 'different from the number of characters in the input'
    assert all(char in {'A', 'B'} for char in S)

if __name__ == '__main__':
    main()
