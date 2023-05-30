//
// Created by micha on 09.05.2023.
//

#ifndef SDIZO_2_GRAPHLIST_H
#define SDIZO_2_GRAPHLIST_H

#include "Edge.h"
#include "TNode.h"

namespace std {

    class GraphList {
        int v; //liczba wierzchołków
    public:
        TNode** lists;
        explicit  GraphList(int v);
        ~GraphList();
        void insert(Edge edge);
        void display();
    };

} // std

#endif //SDIZO_2_GRAPHLIST_H
