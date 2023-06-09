//
// Created by micha on 08.05.2023.
//

#include <iostream>
#include "GraphList.h"
#include "TNode.h"

namespace std {
    GraphList::GraphList(int v) {
        this->v=v;
        lists = new TNode*[v];
        for (int i = 0; i < v; ++i) lists[i] = nullptr;
    }

    GraphList::~GraphList() {
        for (int i = 0; i < v; ++i) delete[] lists[i];
        delete[] lists;
    }

    void GraphList::insert(Edge edge) {
        TNode* temp = new TNode;
        temp->v=edge.n2;
        temp->weight=edge.weight;
        temp->next=lists[edge.n1];
        lists[edge.n1]=temp;
    }

    void GraphList::display() {
        int i;
        TNode *p;

        cout << endl;
        for( i = 0; i < v; i++ ){
            cout << "Vertex " << i << " - ";
            for( p =  lists[ i ]; p; p = p->next ) cout << p->v << ":" << p->weight << " ";
            cout << endl;
        }
    }
} // std