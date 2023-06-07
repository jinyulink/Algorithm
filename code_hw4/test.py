import os
import random

os.system("g++ ek.cpp -o ek") # compile
os.system("g++ ff.cpp -o ff") # compile

open('output_ek.txt', 'w').close()
open('output_ff.txt', 'w').close()

f = open("testcase.in", "w")

n = 100
s = 1
t = 100
c = 2000
f.write(f"{n} {s} {t} {c}\n")
for i in range(c):
    u = random.randint(1, n)
    v = u
    while u == v:
        v = random.randint(1, n)
    w = random.randint(1, 1000000000    )
    f.write(f"{u} {v} {w}\n")
    
os.system("./ek")
os.system("./ff")