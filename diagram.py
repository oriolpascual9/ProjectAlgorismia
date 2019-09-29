import sys
import numpy as np
import matplotlib.pyplot as plt

f = open('data.txt')
probability = []
ncc = []
for line in f:
    q = line.split()
    probability.append(float(q[0]));
    ncc.append(int(q[1]));
f.close

plt.plot(probability, ncc)

Ex = sys.argv[1]
Gr = sys.argv[2]


if Ex == "CCs":
    y_label = 'Number CC'
    g_title = 'Number of Connected Conponents' 
else:
    y_label = 'Dimmension of GC'
    g_title = 'Dimmension of Giant Component' 


if Gr == "RGG":
    x_label = 'Radius r'
else:
    x_label = 'Probability p'

plt.xlabel(x_label)

plt.ylabel(y_label)

plt.title(g_title)

plt.show()
