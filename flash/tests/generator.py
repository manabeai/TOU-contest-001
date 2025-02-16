#!/usr/bin/python

import random

import six

H_MAX = 10 ** 6
H_MIN = 1

N_MAX = 10 ** 6
N_MIN = 1

A_MAX = 10 ** 18

seq = 0
def Generate(N, H, A):
    global seq
    filename = '50-random%02d.in' % seq
    with open(filename, 'w') as f:
        f.write('{} {}\n'.format(H, N))
        f.write(' '.join(map(str, A)))
    seq += 1


def main():
    for _ in six.moves.range(20):
        H = random.randrange(H_MIN, H_MAX)
        N = random.randrange(N_MIN, N_MAX)

        A = random.sample(range(H,A_MAX), N)
        # A = [2] * N
        Generate(N,H,A)


if __name__ == '__main__':
    main()
