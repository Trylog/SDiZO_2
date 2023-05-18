#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "DisjoinedSets.h"
#include "GraphMatrix.h"
#include "MSTree.h"
#include "TNode.h"

using namespace std;

void kruskalMatrix(){   //v - wierzchołki, e - krawędzie

    int v, e, wStart;

    fstream input;
    input.open("dane_droga.txt", ios::in);
    //if (input.good()) {
        input >> e;
        input >> v;
        PriorityQueue queue = PriorityQueue(e);
        input >> wStart;
        if (e) {
            Edge tempIn;
            for (auto i = 0; i < e; ++i) {
                if (!input.eof()) {
                    input >> tempIn.n1;
                    input >> tempIn.n2;
                    input >> tempIn.weight;
                    queue.insert(tempIn);
                } else throw -3; //wrong file length
            }
        }
  //  }



    DisjoinedSets sets = DisjoinedSets(v);
    GraphMatrix matrix = GraphMatrix(v);
    Edge edge;

    for (int i = 0; i < v; ++i) {
        sets.make(i);
    }
    for (int i = 1; i < v; ++i) {
        do{
            edge = queue.minimum();
            queue.deleteMinimum();
        }while(sets.find(edge.n1) == sets.find(edge.n2));

        matrix.insert(edge);
        sets.unite(edge);
    }
    matrix.display();
}

void KruskalList(int v, int e){

}

void buildFromFile(string filePath, MSTree &output, int &v, int &e, int &wStart) {
    fstream input;
    input.open(filePath, ios::in);
    if (input.good()) {
        input >> e;
        input >> v;
        input >> wStart;
        if (e) {
            Edge tempIn;
            for (auto i = 0; i < e; ++i) {
                if (!input.eof()) {
                    input >> tempIn.n1;
                    input >> tempIn.n2;
                    input >> tempIn.weight;
                    output.addEdge(tempIn);
                } else throw -3; //wrong file length
            }
        }
    }
}

void primo(){
    int v, e, wStart;
    fstream input;
    input.open("dane_droga.txt", ios::in);
    //if(input.good()) {
        input >> e;
        input >> v;
        input >> wStart;
        MSTree g(v);
        if (e) {
            Edge tempIn;
            for (auto i = 0; i < e; ++i) {
                if (!input.eof()) {
                    input >> tempIn.n1;
                    input >> tempIn.n2;
                    input >> tempIn.weight;
                    g.addEdge(tempIn);
                } else throw -3; //wrong file length
            }
        }
    //}
    TNode * p;
    Edge eg;
    bool* visited = new bool[v];
    for (int i = 0; i < v; ++i) visited[i] = false;
    PriorityQueue queue = PriorityQueue(e);
    MSTree m(v);



    visited[wStart]= true;
    for (int i = 0; i < v; ++i) {

        for (p = g.getAList(wStart); p ; p=p->next) {
            if (!visited[p->v]) {
                eg.n1 = wStart;
                eg.n2 = p->weight;
                queue.insert(eg);
            }
        }
        do {
            eg=queue.minimum();
            queue.deleteMinimum();
        } while (visited[eg.n2]);
        m.addEdge(eg);
        visited[eg.n2] = true;
        wStart=eg.n2;
    }
    m.print();
}

void PrimList(int v, int e) {

}



int main() {

    //primo();
    kruskalMatrix();
    system("pause");

    return 0;
}