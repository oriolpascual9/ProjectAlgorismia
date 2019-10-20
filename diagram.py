import sys
import numpy as np
import matplotlib.pyplot as plt

propriedad = sys.argv[1]
tipo_grafo = sys.argv[2]

f = open('data.txt')
probability = []
ncc = []
for line in f:
    q = line.split()
    probability.append(float(q[0]));
    if propriedad in ["Conexo", "Aciclico", "CH"]:
        ncc.append(float(q[1]));
    if propriedad in ["CC", "CG" ,"DM"]:
        ncc.append(int(q[1]));
f.close

dx = {
    "RGG": "Radius r",
    "BRG": "Probability p",
    "BAG": "Número de aristas a conectar desde un nuevo nodo a los nodos existentes"
}

dy = {
    "Conexo": "Probabilidad de que el grafo es conexo",
    "CC": "Numero de componentes conexas",
    "CG": "Dimension de la componente gigante",
    "CH": "Probabilidad de que tiene un camino hamiltoniano",
    "DM": "Diametro del Grafo",
    "Aciclico": "Probabilidad de que el grapho es aciclico"
}

dt = {
    "RGG": "Random Geometric Graph",
    "BRG": "Binomial Random Graph",
    "BAG": "Barabási–Albert Grpah"
}

plt.plot(probability, ncc)

x_label = dx[tipo_grafo]
y_label = dy[propriedad]
g_title = dt[tipo_grafo]

plt.xlabel(x_label)
plt.ylabel(y_label)
plt.title(g_title)

plt.show()
