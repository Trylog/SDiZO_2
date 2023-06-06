#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "PriorityQueue.h"
#include "DisjoinedSets.h"
#include "GraphMatrix.h"
#include "MSTree.h"
#include "TNode.h"
#include "GraphList.h"
#include "Queue.h"

using namespace std;

void displayM(string nazwa, bool mst){
    int v, e, f;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    if(mst) input >> f;
    GraphMatrix matrix = GraphMatrix(v);
    if (e) {
        Edge tempIn;
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                matrix.insert(tempIn);
            } else throw -3; //wrong file length
        }
        matrix.display();
    }
    //  }
}

void displayL(string nazwa, bool mst){
    int v, e, f;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    if(mst) input >> f;
    GraphList matrix = GraphList(v);
    if (e) {
        Edge tempIn;
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                matrix.insert(tempIn);
            } else throw -3; //wrong file length
        }
        matrix.display();
    }
    //  }
}

void kruskalMatrix(/*string nazwa*/int** mInput, int v, int e){   //v - wierzchołki, e - krawędzie

    /*int v, e;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
        input >> e;
        input >> v;
        PriorityQueue queue = PriorityQueue(e);
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
*/
    PriorityQueue queue = PriorityQueue(e);
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if(mInput[i][j]!=0){
                Edge temp;
                temp.n1 = i;
                temp.n2 = j;
                temp.weight = mInput[i][j];
            }
        }
    }


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

void kruskalList(string nazwa){
    int v, e;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    PriorityQueue queue = PriorityQueue(e);
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
    MSTree matrix = MSTree(v);
    Edge edge;

    for (int i = 0; i < v; ++i) {
        sets.make(i);
    }
    for (int i = 1; i < v; ++i) {
        do{
            edge = queue.minimum();
            queue.deleteMinimum();
        }while(sets.find(edge.n1) == sets.find(edge.n2));

        matrix.addEdge(edge);
        sets.unite(edge);
    }
    matrix.print();
}

void primList(string nazwa){
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
    PriorityQueue queue = PriorityQueue(e);
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

void primMatrix(string nazwa) {
    int v, e, wStart=0;
    fstream input;
    input.open(nazwa, ios::in);
    //if(input.good()) {
    input >> e;
    input >> v;

    GraphMatrix g(v);
    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                g.insert(tempIn);
                g.insert(Edge{tempIn.n2, tempIn.n1, tempIn.weight});
            } else throw -3; //wrong file length
        }
    }
    //}
    TNode * p;
    Edge eg{};
    bool* visited = new bool[v];
    for (int i = 0; i < v; ++i) visited[i] = false;
    PriorityQueue queue = PriorityQueue(e);
    GraphMatrix m(v);


    visited[wStart]= true;
    for (int i = 0; i < v; ++i) {

        for (int j = 0;j<v;j++) {
            if(g.matrix[wStart][j] == 0)continue;
            if (!visited[j]) {
                eg.n1 = wStart;
                eg.n2 = j;
                eg.weight=g.matrix[wStart][j];
                queue.insert(eg);
            }
        }
        do {
            eg=queue.minimum();
            queue.deleteMinimum();
        } while (visited[eg.n2] && queue.size);
        if(queue.size) {
            m.insert(eg);
            visited[eg.n2] = true;
            wStart = eg.n2;
        }
    }
    m.display();
}

void dijkstraMatrix(string nazwa){
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
    int minWeightNr=0;
    for (int j = 0; j < v; ++j) {
        for (int i = 0; i < v; ++i){
            if(wasVisited[i] == 1) minWeightNr = i;
        }
        for (int i = 0; i < v; ++i) {
            if (wasVisited[i] == 1 && weight[i] < weight[minWeightNr])minWeightNr = i;
        }
        //(wasVisited[temp->v] == 0 || wasVisited[temp->v] != 2 && weight[temp->v] > weight[minWeightNr] + temp->weight)
        for (int i = 0; i < v; ++i) {
            if (matrix[minWeightNr][i] != 0 && (wasVisited[i] == 0 || wasVisited[i] != 2 && weight[i] > weight[minWeightNr] + matrix[minWeightNr][i])) {
                weight[i] = weight[minWeightNr] + matrix[minWeightNr][i];
                predecessor[i] = minWeightNr;
                wasVisited[i] = 1;
            }
        }
        wasVisited[minWeightNr] = 2;
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

void dijkstraList(string nazwa){
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
    int minWeightNr=0;
    TNode* temp;
    for (int j = 0; j < v; ++j) {
        for (int i = 0; i < v; ++i){
            if(wasVisited[i] == 1) minWeightNr = i;
        }
        for (int i = 0; i < v; ++i) {
            if (wasVisited[i] == 1 && weight[i] < weight[minWeightNr])minWeightNr = i;
        }

        for (temp = list.lists[minWeightNr]; temp; temp = temp->next) {
            if ((wasVisited[temp->v] == 0 || wasVisited[temp->v] != 2 && weight[temp->v] > weight[minWeightNr] + temp->weight)) {
                weight[temp->v] = weight[minWeightNr] + temp->weight;
                predecessor[temp->v] = minWeightNr;
                wasVisited[temp->v] = 1;
            }
        }
        wasVisited[minWeightNr] = 2;
    }

    for (int i = 0; i < v; ++i) {
        cout<<i<<" ["<<weight[i]<<"]:";
        int end = i;
        //cout<<predecessor[i];
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
        cout<<i<<" ["<<weight[i]<<"]:";
        int end = i;
        while(end!=firstV){
            end = predecessor[end];
            cout<<" "<<end;
        }
        cout<<endl;
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
        cout<<i<<" ["<<weight[i]<<"]:";
        int end = i;
        //cout<<predecessor[i];
        while(end!=firstV){
            end = predecessor[end];
            cout<<" "<<end;
        }
        cout<<endl;
    }

    for (int i = 0; i < v; ++i) {
        for (temp = list.lists[i]; temp; temp = temp->next) {
            if (weight[temp->v] > weight[i] + temp->weight) return false;
        }
    }
    return true;
}

bool DFS(int** graph, int v, int* predecessor, bool* visited, int source, int sink){
    if(sink == source)return true;

    visited[source] = true;

    for (int i = 0; i < v; ++i) {
        if (graph[source][i] > 0 && !visited[i]){
            predecessor[i] = source;
            if(DFS(graph, v, predecessor, visited, source, sink))return true;
        }
    }
    return false;
}

void fordFulkerson(string nazwa){

    int v, e, source, sink;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> source;
    input >> sink;

    int maxFlow = 0, residPathThroughput;
    int* predecessor = new int[v];
    bool* visited = new bool[v];
    int** residVerticesThroughput = new int*[v];
    for (int i = 0; i < v; ++i) {
        residVerticesThroughput[i] = new int[v];
        for (int j = 0; j < v;++j) residVerticesThroughput[i][j]=0;
        visited[i] = false;
    }

    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                residVerticesThroughput[tempIn.n1][tempIn.n2] = tempIn.weight;
            } else throw -3; //wrong file length
        }
    }

    while (DFS(residVerticesThroughput, v, predecessor, visited, source, sink)){
        for (int i = 0; i < v; ++i) visited[i] = false;
        residPathThroughput = INT32_MAX;

        for (int i = sink; i != source; i = predecessor[i]) {
            residPathThroughput = min(residPathThroughput, residVerticesThroughput[predecessor[i]][i]);
        }
        for (int i = sink; i != source; i = predecessor[i]) {
            auto p = predecessor[i];
            residVerticesThroughput[p][i] -= residPathThroughput;
            residVerticesThroughput[i][p] -= residPathThroughput;
        }
        maxFlow += residPathThroughput;
    }


}
bool edmondsKarp(string nazwa){

    int v, e, source, sink;

    fstream input;
    input.open(nazwa, ios::in);
    //if (input.good()) {
    input >> e;
    input >> v;
    input >> source;
    input >> sink;

    Queue queue;
    bool flag;
    int maxFlow = 0, n1, residVertexThroughput;
    int* predecessor = new int[v];
    int* pathResidThroughput = new int[v];
    int** throughput = new int*[v];
    int** flow = new int*[v];
    for (int i = 0; i < v; ++i) {
        throughput[i] = new int[v];
        for (int j = 0; j < v;++j) throughput[i][j]=0;
        flow[i] = new int[v];
        for (int j = 0; j < v;++j) flow[i][j]=0;
    }

    if (e) {
        Edge tempIn{};
        for (auto i = 0; i < e; ++i) {
            if (!input.eof()) {
                input >> tempIn.n1;
                input >> tempIn.n2;
                input >> tempIn.weight;
                throughput[tempIn.n1][tempIn.n2] = tempIn.weight;
            } else throw -3; //wrong file length
        }
    }

    while (true){
        for (int i = 0; i < v; ++i) predecessor[i] = -1;
        predecessor[source] = -2;
        pathResidThroughput[source] = INT32_MAX;

        queue.empty();
        queue.push(source);
        flag = false;

        while (!queue.isEmpty()){
            n1 = queue.first();
            queue.pop();
            for (int n2 = 0; n2 < v; ++n2) {
                residVertexThroughput = throughput[n1][n2] - flow[n1][n2];
                if (residVertexThroughput || predecessor[n2] != -1) continue;

                predecessor[n2] = n1;
                pathResidThroughput[n1] = min(pathResidThroughput[n2], residVertexThroughput);

                //skok

                if(n2 == sink){
                    maxFlow += pathResidThroughput[sink];
                    int a = n2;
                    while (1 != source){
                        n1 = predecessor[a];
                        flow[n1][a] += pathResidThroughput[sink];
                        flow[a][n1] -= pathResidThroughput[sink];
                    }
                    flag = true;
                    break;
                }
                queue.push(n2);
            }
            if(flag) break;
        }
        if (!flag) break;
    }



}

int** generateMatrix(int v, int density){

}

Edge* generateList(int v, int density){

}

void tests(){
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 20);
    double time = 0.0;
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    int lV[7] = {10,20,40,60,80,100, 150};
    int density[3] = {20,60,99};
    for (int n : lV){
        for (int m : density) {
            for (int i = 0; i < 50; ++i) {
                auto g = generateMatrix(n, m);
                t1 = std::chrono::high_resolution_clock::now();
                kruskalMatrix(g, n, (n*n*m)/100);
                t2 = std::chrono::high_resolution_clock::now();
            }
            auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            time += time_span.count();
        }
    }

}


int main() {/*
    dijkstraMatrix("dane_droga_sk1.txt");
    cout<<endl;
    dijkstraList("dane_droga_sk1.txt");
    cout<<endl;
    bfList("dane_droga_sk1.txt");
    cout<<endl;
    bfMatrix("dane_droga_sk1.txt");
    cout<<endl<<endl;
    kruskalList("dane_mst2.txt");
    cout<<endl;
    primList("dane_mst2.txt");
    cout<<endl;
    kruskalMatrix("dane_mst2.txt");
    cout<<endl;
    primMatrix("dane_mst2.txt");
/*
    cout<<"podaj algorytm"<<endl;
    string odp="";
    cin>>odp;
    if(odp=="mstM"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        kruskalMatrix(odp);
        primMatrix(odp);
    } else if(odp=="mstL"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        kruskalList(odp);
        primList(odp);
    } else if(odp=="drogaL"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        dijkstraList(odp);
        bfList(odp);
    } else if(odp=="drogaM"){
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        dijkstraMatrix(odp);
        bfMatrix(odp);
    } else if(odp=="displayM"){
        cout<< "Czy mst?"<<endl;
        bool mst;
        cin>>mst;
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        displayM(odp, mst);
    }
    else if(odp=="displayL"){
        cout<< "Czy mst?"<<endl;
        bool mst;
        cin>>mst;
        cout<<"Podaj nazwe pliku"<<endl;
        odp="";
        cin>>odp;
        displayL(odp, mst);
    }
    //cout<<"Podaj nazwe pliku"<<endl;
    //primo();
    //kruskalMatrix();*/
    system("pause");

    return 0;
}