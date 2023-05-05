import random
import os

with open("testcase.in", "w") as f:
    H = random.randint(1, 500)
    W = random.randint(1, 500)
    K = random.randint(1, 5000)
    f.write(f"{H} {W} {K}\n")
    for i in range(K):
        num = random.randint(1, 100)
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
        
