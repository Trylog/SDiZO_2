#include <iostream>
#include "PriorityQueue.h"
#include "DisjoinedSets.h"
#include "GraphMatrix.h"
#include "MSTree.h"
#include "TNode.h"

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
        queue.insert();
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

void KruskalList(int v, int e){

}

void Prim(int v, int e, int wStart){

    TNode * p;
    Edge eg;
    bool* visited = new bool[e];
    for (int i = 0; i < e; ++i) visited[i] = false;
    PriorityQueue queue = PriorityQueue(e);
    MSTree m(v);
    MSTree g(v);
    visited[wStart]= true;
    for (int i = 0; i < e; ++i) {
        //TODO wczytywanie krawędzi
        g.addEdge(eg);
    }
    for (p = g.getAList(wStart); p ; p=p->next) {
        if(!visited[p->v]){
            eg.n1=wStart;
            eg.n2=p->weight;
            queue.insert(eg);
        }
        do {
            eg=queue.minimum();
            queue.deleteMinimum();
        } while (visited[eg.n2]);
        m.addEdge(eg);
        visited[eg.n2] = true;
        wStart=eg.n2;
    }

}

void PrimList(int v, int e) {

}



int main() {



    return 0;
}