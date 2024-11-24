#!/usr/bin/python

import random
import six
import General 


def Large_1():
    N = 10
    H = 10 ** 6

    A = [H]
    for i in six.moves.range(N-1):
        A.append(A[-1] + (H*2-1))

    General.write_to_file(H, N, A, "large_1.in")

def Large_2():
    N = 10 ** 6
    H = 10 ** 6

    A = [H]
    for i in six.moves.range(N-1):
        A.append(A[-1] + (H*2-1))

    General.write_to_file(H, N, A, "large_2.in")

def main():
    # Large_1()
    Large_2()

if __name__ == '__main__':
    main()
