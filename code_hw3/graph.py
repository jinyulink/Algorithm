import numpy as np
import matplotlib.pyplot as plt

f = open("output2.txt", "r")

x = []
y = []

for lines in f.readlines():
    y.append(float(lines))

for i in range(0, 10000000, 10000):
    x.append(i)
    
b, a = np.polyfit(x, y, deg=1)
xseq = np.linspace(0, 10000000, num=1000)
    
# plt.plot(x, y, label='time')
plt.scatter(x, y, label = 'time(sec.)', s = 5)
plt.plot(xseq, a + b * xseq, color="k", lw=2.5, label='regression line');
plt.xlim((0,10001000))
plt.ylim((0,4.3))
plt.grid()
plt.legend()
plt.show()