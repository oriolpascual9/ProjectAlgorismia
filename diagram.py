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

plt.xlabel('Probability')

plt.ylabel('Number CC')

plt.show()

