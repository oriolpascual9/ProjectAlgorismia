import networkx as nx
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

# plt.plot([0.0, 1], [1.0, 1], 'red', lw=0.7)

plt.xlabel('Radius r')

plt.ylabel('Number CC')

plt.title('Number of Connected Conponents of a Random Geometric Graph')

plt.show()
