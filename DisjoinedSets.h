//
// Created by micha on 08.05.2023.
//

#ifndef SDIZO_2_DISJOINEDSETS_H
#define SDIZO_2_DISJOINEDSETS_H

#include "Edge.h"

namespace std {

    class DisjoinedSets {
        struct Node{
            int parent, rank;
        };
        Node* sets;
    public:
        explicit DisjoinedSets(int v);//liczba wierzchołków
        ~DisjoinedSets();
        int find(int a);
        void unite(Edge edge);
        void make(int a);
    };

} // std

#endif //SDIZO_2_DISJOINEDSETS_H
