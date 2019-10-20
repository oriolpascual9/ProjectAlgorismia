import sys
import networkx as nx

propriedad = sys.argv[1]
n = int(sys.argv[2])
print (propriedad)

if propriedad == "DM":
    f = open('data.txt', 'w')
    for i in range(1, n):
        x = 0
        for j in range(0, 100):
            G = nx.barabasi_albert_graph(n, i)
            x = x + nx.diameter(G)
        f.write("%d\t%d\n" % (i, int(x/100.0)))
    f.close()
if propriedad == "Aciclico":
    f = open('data.txt', 'w')
    for i in range(1, n):
        x = 0
        y = 0
        for j in range(0, 100):
            G = nx.barabasi_albert_graph(n, i)
            try:
                nx.find_cycle(G)
                x = x + 1
            except:
                y = y + 1
        f.write("%d\t%f\n" % (i, float(x) / (x+y)))
    f.close()
