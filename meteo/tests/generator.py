#!/usr/bin/python

import random
H_MIN = 1
H_MAX = 10

W_MIN = 1
W_MAX = 10

A_MIN = 0
A_MAX = 100

seq = 0

def Generate():
    global seq
    H = random.randint(H_MIN, H_MAX)
    W = random.randint(W_MIN, W_MAX)
    filename = '50-random%02d.in' % seq
    with open(filename, 'w') as f:
        f.write(f"{H} {W}\n")
        for i in range(H):
            row = [str(random.randint(A_MIN, A_MAX)) for _ in range(W)]
            f.write(" ".join(row) + "\n")
    seq += 1

def main():
    for _ in range(20):
        Generate()

if __name__ == "__main__":
    main()