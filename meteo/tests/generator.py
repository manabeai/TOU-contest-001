#!/usr/bin/python

import random

seq = 0

def Generate():
    global seq
    H = random.randint(1, 10)
    W = random.randint(1, 10)
    filename = '50-random%02d.in' % seq
    with open(filename, 'w') as f:
        f.write(f"{H} {W}\n")
        for i in range(H):
            row = [str(random.randint(0, 100)) for _ in range(W)]
            f.write(" ".join(row) + "\n")
    seq += 1

def main():
    for _ in range(20):
        Generate()

if __name__ == "__main__":
    main()