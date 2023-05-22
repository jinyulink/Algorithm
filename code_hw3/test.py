import os
import random
import numpy as np

os.system("g++ 110403518_林晉宇_hw3.cpp -o t") # compile

open('output2.txt', 'w').close()

for i in range(1, 10000000, 10000):
    print("case: ", i)
    K = random.randint(1, 1000) 
    N = i
    f = open("testcase.in", "w")
    f.write(f"{K} {N}\n")
    B = np.random.randint(100000, size = N)
    for j in B:
        f.write(f"{j} ")
    os.system("./t")