//
// Created by micha on 08.05.2023.
//

#include "DisjoinedSets.h"
#include "Edge.h"

namespace std {
    DisjoinedSets::DisjoinedSets(int v) {
        sets = new Node[v];
    }

    DisjoinedSets::~DisjoinedSets() {
        delete[] sets;
    }

    int DisjoinedSets::find(int a) {
        if(sets[a].parent!=a) sets[a].parent = find(sets[a].parent);
        return sets[a].parent;
    }

    void DisjoinedSets::unite(Edge edge) {
        auto x = find(edge.n1);
        auto y = find(edge.n2);
        if(sets[x].rank < sets[y].rank){
            sets[x].parent=y;
        } else{
            sets[y].parent=x;
            if(sets[x].rank == sets[y].rank) sets[x].rank++;
        }
    }

    void DisjoinedSets::make(int a) {
        sets[a].parent = a;
        sets[a].rank = 0;
    }
} // std