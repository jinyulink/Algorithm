import os
import random

os.system("g++ ek.cpp -o ek") # compile
os.system("g++ ff.cpp -o ff") # compile

open('output_ek.txt', 'w').close()
open('output_ff.txt', 'w').close()

f = open("testcase.in", "w")

n = 50 #最多 n*(n-1)
s = 1
t = n
c = n*n-n
f.write(f"{n} {s} {t} {c}\n")
for u in range(1, n+1):
    for v in range(1, n+1):
        if u == v:
            continue
        w = random.randint(1, 100000)
        f.write(f"{u} {v} {w}\n")
    
os.system("./ek")
os.system("./ff")