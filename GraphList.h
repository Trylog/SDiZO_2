//
// Created by micha on 09.05.2023.
//

#ifndef SDIZO_2_GRAPHLIST_H
#define SDIZO_2_GRAPHLIST_H

#include "Edge.h"

namespace std {

    class GraphList {
        Edge** lists;
        int v; //liczba wierzchołków
    public:
        explicit  GraphList(int v);
        ~GraphList();
        void insert(Edge edge);
        void display();
    };

} // std

#endif //SDIZO_2_GRAPHLIST_H
