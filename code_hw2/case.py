import os
import random
import time
import numpy as np
import matplotlib.pyplot as plt

# 產生測資
# W(1000) H(1000) K(random(10000)) 
# Q(100) 接著Q個座標

# 第一種作法為O(KHW)
# 第二種做法為O(WH+KQ^2)

os.system("g++ KHW.cpp -o khw") # compile
os.system("g++ dp2.cpp -o dp2") # compile

open('output.txt', 'w').close()
open('output1.txt', 'w').close()

khw_graph = []
dp_graph = []

H = 1000
W = 1000
k = 100
for K in range(k,k+1):
    print(K)
    f = open("testcase.in", "w")
    f.write(f"{H} {W} {K}\n")
    for i in range(K):
        num = 100
        f.write(f"{num} ")
        for j in range(num):
            VorH = random.randint(0, 1)  # 0: vertical, 1: horizontal
            if VorH == 0:
                x = random.randint(0, H)
                y = random.randint(0, W-1)
                f.write(f"{y} {x} {y+1} {x} ")
            else:
                x = random.randint(0, H-1)
                y = random.randint(0, W)
                f.write(f"{y} {x} {y} {x+1} ")
        f.write("\n")
    os.system("./khw &") # run https://blog.csdn.net/Mr_Li1/article/details/89353276
    os.system("./dp2 &") # run
    # with open('output.txt', 'r') as f:
        # khw_time = f.readlines()[-1]
    # with open('output1.txt', 'r') as f:
        # dp_time = f.readlines()[-1]
    # khw_graph.append(khw_time)
    # dp_graph.append(dp_time)
    
# x = np.arange(1,k+1,1)
# plt.plot(x, khw_graph, label='KHW')
# plt.plot(x, dp_graph, label='dp')
# plt.legend()

# plt.show()
# plt.savefig('foo.png')