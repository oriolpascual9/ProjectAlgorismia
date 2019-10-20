import networkx as nx

G = nx.Graph()
G = nx.barabasi_albert_graph(20, 10)

f = open('graph.txt', "w+")

f.write("%d\n" %G.number_of_nodes())
l = list(G.edges())
for i, j in l:
    f.write("%d\t%d\n" % (i, j))

f.close()
