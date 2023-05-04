# 測試從1位數到5000位數 測資

import random
import os
import numpy as np
import matplotlib.pyplot as plt

os.system("g++ n2.cpp -o n2") # compile
os.system("g++ karatsuba.cpp -o karatsuba") # compile

open('n2.txt', 'w').close()
open('karatsuba.txt', 'w').close()

r=100  # 位數

for i in range(0,r+1):
    # print(str(i)+" 位數 ")
    n = ""  
    m = ""
    n += str(random.randrange(1,10))
    m += str(random.randrange(1,10))
    for j in range(0,i-1):
        n += str(random.randrange(10))
        m += str(random.randrange(10))
    f=open("number.txt","w")
    f.write(n) 
    f.write("\n")
    f.write(m)
    if  i==0:
        continue
    os.system('n2')
    os.system("karatsuba")
    
        
    
f1=open("n2.txt","r")
f2=open("karatsuba.txt","r")

x = np.linspace(1, r, int(r/1))
f1y = []
f2y = []

tmp1=0
tmp2=0

for line in f1.readlines():
    f1y.append(float(line))
for line in f2.readlines():
    f2y.append(float(line))

print(len(f1y))
print(len(f2y))

plt.plot(x, f1y, label='n2')
plt.plot(x, f2y, label='karatsuba')
plt.legend()

plt.show()
plt.savefig('foo.png')