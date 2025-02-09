#!/usr/bin/python

import random

def generate_test_case():
    H = random.randint(1, 10)
    W = random.randint(1, 10)
    
    print(f"{H} {W}")
    
    for i in range(H):
        row = [str(random.randint(0, 100)) for _ in range(W)]
        print(" ".join(row))

if __name__ == "__main__":
    generate_test_case()