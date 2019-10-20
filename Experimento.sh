#!/bin/bash
if [ $# -lt 3 ];
then
    echo "\nUsage: sh Experimento.sh Propriedad_a_estudiar Tipo_de_grafo Numero_de_vertices_del_grafo\n\
Propriedad:\n\
    CC       - Numero de Componentes Conexas\n\
    CG       - Dimension Componente Gigante\n\
    Conexo   - Conexidad del Grafo\n\
    Aciclico - Propredad de ser Aciclico\n\
    CH       - Tener Camino Hamiltoniano
Tipo de grafo:\n\
    RGG      - Random Geometric Graph\n\
    BRG      - Binomial Random Graph\n\
    BAG      - Barabási–Albert Grpah\n\n"
else
    ./main.exe $1 $2 $3 $4
    python3 diagram.py $1 $2
fi
