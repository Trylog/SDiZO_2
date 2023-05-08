#include <iostream>
#include "PriorityQueue.h"
#include "DisjoinedSets.h"
#include "GraphMatrix.h"

using namespace std;

void kruskalMatrix(int v, int e){   //v - wierzchołki, e - krawędzie

    PriorityQueue queue = PriorityQueue(e);
    DisjoinedSets sets = DisjoinedSets(v);
    GraphMatrix matrix = GraphMatrix(v);
    Edge edge;

    for (int i = 0; i < v; ++i) {
        sets.make(i);
    }
    for (int i = 0; i < e; ++i) {
        //TODO wczytywanie krawędzi do kolejki
    }
    for (int i = 1; i < v; ++i) {
        do{
            edge = queue.minimum();
            queue.deleteMinimum();
        }while(sets.find(edge.n1) == sets.find(edge.n2));

        matrix.insert(edge);
        sets.unite(edge);
        matrix.display();
    }
}





int main() {



    return 0;
}
