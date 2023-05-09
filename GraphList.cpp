//
// Created by micha on 08.05.2023.
//

#include "GraphList.h"

namespace std {
    GraphList::GraphList(int v) {
        this->v=v;
        lists = new Edge*[v];
        for (int i = 0; i < v; ++i) lists[i] = nullptr;
    }

    GraphList::~GraphList() {
        for (int i = 0; i < v; ++i) delete[] lists[i];
        delete[] lists;
    }

    void GraphList::insert(Edge edge) {


    }
} // std