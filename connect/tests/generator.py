#!/usr/bin/python

# a = "AAAAB"
# S = ""
# n = 10 ** 5
# while len(S)+5 <= n:
#     S = S + a

# print(len(S), n)
# print(S)


import random

import six

import re
import sys

N_MIN = 3
N_MAX = 10 ** 5

k_MIN = 3
k_MAX = N_MAX

seq = 0
def Generate(N, k, S):
    global seq
    filename = '50-random%02d.in' % seq
    with open(filename, 'w') as f:
        f.write('{} {}\n'.format(N, k))
        f.write('{}\n'.format(S) )
    seq += 1


def main():
    for _ in six.moves.range(20):
        N = random.randrange(N_MIN, N_MAX)
        k_MAX = N
        k = random.randrange(k_MIN, k_MAX)
        S = ''.join(random.choice('AB') for _ in range(N))
        Generate(N, k, S)


if __name__ == '__main__':
    main()
