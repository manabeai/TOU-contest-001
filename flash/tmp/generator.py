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

def Random_Large():
    N = random.randint(10 ** 5, 10 ** 6)
    H = random.randint(10 ** 5, 10 ** 6)
    A = []
    st = set()
    for i in six.moves.range(N):
        
        appended = False
        while appended == False:
            x = random.randint(H, 10 ** 18)
            if x not in st:
                A.append(x)
                st.add(x)
                appended = True
            
    assert(len(A) == N)
    General.write_to_file(H,N,A,"random_large_1.in")
            
def main():
    # Large_1()
    # Large_2()
    Random_Large()

if __name__ == '__main__':
    main()
