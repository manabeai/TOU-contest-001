#!/usr/bin/python

import re
import sys

N_MIN = 3
N_MAX = 10 ** 5

k_MIN = 3
k_MAX = N_MAX

def main():
    
    m = re.match(r'^(\d+) (\d+)\n$', sys.stdin.readline())
    S = re.match(r'^[AB]{3,}$', sys.stdin.readline())
    assert m, 'Does not match with regexp'
    N,k = map(int, m.groups())
    assert N_MIN <= N <= N_MAX, 'a out of range: %d' % N
    assert k_MIN <= k <= k_MAX, 'a out of range: %d' % k

if __name__ == '__main__':
    main()
