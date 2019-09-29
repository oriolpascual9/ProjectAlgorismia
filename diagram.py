import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

f = open('data.txt')
data = []
for line in f:
    q = line.split()
    a = float(q[0])
    b = int(q[1])
    data.append((b, a))
f.close

plt.plot(data)

plt.show()

