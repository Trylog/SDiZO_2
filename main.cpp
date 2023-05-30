#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include "DisjoinedSets.h"
#include "GraphMatrix.h"
#include "MSTree.h"
#include "TNode.h"
#include "EdgeDij.h"
#include "GraphList.h"

using namespace std;

void kruskalMatrix(string nazwa){   //v - wierzchołki, e - krawędzie

    int v, e;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
        input >> e;
        input >> v;
        PriorityQueue<Edge> queue = PriorityQueue<Edge>(e);
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

void primo(string nazwa){
    int v, e, wStart=0;
    fstream input;
    input.open(nazwa, ios::in);
    //if(input.good()) {
        input >> e;
        input >> v;

        MSTree g(v);
        if (e) {
            Edge tempIn{};
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
    Edge eg{};
    bool* visited = new bool[v];
    for (int i = 0; i < v; ++i) visited[i] = false;
    PriorityQueue<Edge> queue = PriorityQueue<Edge>(e);
    MSTree m(v);


    visited[wStart]= true;
    for (int i = 0; i < v; ++i) {

        for (p = g.getAList(wStart); p; p=p->next) {
            if (!visited[p->v]) {
                eg.n1 = wStart;
                eg.n2 = p->v;
                eg.weight=p->weight;
                queue.insert(eg);
            }
        }
        do {
            eg=queue.minimum();
            queue.deleteMinimum();
        } while (visited[eg.n2] && queue.size);
        if(queue.size) {
            m.addEdge(eg);
            visited[eg.n2] = true;
            wStart = eg.n2;
        }
    }
    m.print();
}

void PrimList(int v, int e) {

}

void DijkstraMatrix(string nazwa){
    int v, e, firstV;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> firstV;
    int** matrix = new int*[v];
    for (int i = 0; i < v; ++i) {
        matrix[i] = new int[v];
        for (int j = 0; j < v; ++j) matrix[i][j]=0;
    }
    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                matrix[tempIn.n1][tempIn.n2] = tempIn.weight;
            } else throw -3; //wrong file length
        }
    }
    //  }
    int* weight = new int[v];
    int* predecessor = new int[v];
    auto* wasVisited = new short[v];
    for (int i = 0; i < v; ++i) wasVisited[i] = 0;
    weight[firstV] = 0;
    predecessor[firstV] = -1;
    wasVisited[firstV] = 1;
    int minWeight=0;
    for (int j = 0; j < v; ++j) {
        for (int i = 0; i < v; ++i) {
            if (wasVisited[i] == 1 && weight[i] < minWeight)minWeight = i;
        }
        wasVisited[minWeight] = 2;
        for (int i = 0; i < v; ++i) {
            if (matrix[minWeight][i] != 0 && wasVisited[i] != 2 &&
                (weight[i] > weight[minWeight] + matrix[minWeight][i] || wasVisited[i] == 0)) {
                weight[i] = weight[minWeight] + matrix[minWeight][i];
                predecessor[i] = minWeight;
                wasVisited[i] = 1;
            }
        }
    }

    for (int i = 0; i < v; ++i) {
        cout<<i<<" ["<<weight[i]<<"]:";
        int end = i;
        while(end!=firstV){
            end = predecessor[end];
            cout<<" "<<end;
        }
        cout<<endl;
    }

}

void DijkstraList(string nazwa){
    int v, e, firstV;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> firstV;
    GraphList list = GraphList(v);
    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                list.insert(tempIn);
            } else throw -3; //wrong file length
        }
    }
    //  }
    int* weight = new int[v];
    int* predecessor = new int[v];
    auto* wasVisited = new short[v];
    for (int i = 0; i < v; ++i) wasVisited[i] = 0;
    weight[firstV] = 0;
    predecessor[firstV] = -1;
    wasVisited[firstV] = 1;
    int minWeight=0;
    TNode* temp;
    for (int j = 0; j < v; ++j) {
        for (int i = 0; i < v; ++i) {
            if (wasVisited[i] == 1 && weight[i] < minWeight)minWeight = i;
        }
        wasVisited[minWeight] = 2;
        for (temp = list.lists[j]; temp; temp = temp->next) {
            if ((wasVisited[temp->v] == 0 || wasVisited[temp->v] != 2 &&weight[temp->v] > weight[minWeight] + temp->weight)) {
                weight[temp->v] = weight[minWeight] + temp->weight;
                predecessor[temp->v] = minWeight;
                wasVisited[temp->v] = 1;
            }
        }
    }

    for (int i = 0; i < v; ++i) {
        cout<<i<<" ["<<weight[i]<<"]:";
        int end = i;
        while(end!=firstV){
            end = predecessor[end];
            cout<<" "<<end;
        }
        cout<<endl;
    }

}

bool bfMatrix(string nazwa){

    int v, e, firstV;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> firstV;
    int** matrix = new int*[v];
    for (int i = 0; i < v; ++i) {
        matrix[i] = new int[v];
        for (int j = 0; j < v; ++j) matrix[i][j]=0;
    }
    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                matrix[tempIn.n1][tempIn.n2] = tempIn.weight;
            } else throw -3; //wrong file length
        }
    }
    //  }
    int* weight = new int[v];
    int* predecessor = new int[v];
    auto* wasVisited = new bool [v];
    for (int i = 0; i < v; ++i) wasVisited[i] = 0;

    wasVisited[firstV] = true;
    weight[firstV] = 0;
    predecessor[firstV] = -1;

    bool changes;
    for (int i = 1; i < v; ++i) {
        changes = false;
        for (int j = 0; j < v; ++j) {
            if(!wasVisited[j])continue;
            for (int k = 0; k < v; ++k) {
                if (matrix[j][k] == 0) continue;
                if(!wasVisited[k] || weight[k] > weight[j] + matrix[j][k]){
                    changes = true;
                    wasVisited[k] = true;
                    weight[k] = weight[j] + matrix[j][k];
                    predecessor[k] = j;
                }
            }
        }
        if (!changes) break;
    }

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (matrix[i][j] == 0) continue;
            if (weight[j] > weight[i] + matrix[i][j]) return false;
        }
    }
    return true;
}

bool bfList(string nazwa){

    int v, e, firstV;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> firstV;
    GraphList list = GraphList(v);
    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                list.insert(tempIn);
            } else throw -3; //wrong file length
        }
    }
    //  }
    int* weight = new int[v];
    int* predecessor = new int[v];
    auto* wasVisited = new bool [v];
    for (int i = 0; i < v; ++i) wasVisited[i] = 0;

    wasVisited[firstV] = true;
    weight[firstV] = 0;
    predecessor[firstV] = -1;

    bool changes;
    TNode* temp;
    for (int i = 1; i < v; ++i) {
        changes = false;
        for (int j = 0; j < v; ++j) {
            if(!wasVisited[j])continue;
            for (temp = list.lists[j]; temp; temp = temp->next) {
                if(!wasVisited[temp->v] || weight[temp->v] > weight[j] + temp->weight){
                    changes = true;
                    wasVisited[temp->v] = true;
                    weight[temp->v] = weight[j] + temp->weight;
                    predecessor[temp->v] = j;
                }
            }
        }
        if (!changes) break;
    }

    for (int i = 0; i < v; ++i) {
        for (temp = list.lists[i]; temp; temp = temp->next) {
            if (weight[temp->v] > weight[i] + temp->weight) return false;
        }
    }
    return true;
}

int main() {
    cout<<"podaj algorytm"<<endl;
    string odp="";
    cin>>odp;
    if(odp=="kruskal"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        kruskalMatrix(odp);
    }
    if(odp=="prim"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        primo(odp);
    }
    //cout<<"Podaj nazwe pliku"<<endl;
    //primo();
    //kruskalMatrix();
    system("pause");

    return 0;
}