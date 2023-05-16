//
// Created by micha on 16.05.2023.
//

#ifndef SDIZO_2_MSTREE_H
#define SDIZO_2_MSTREE_H

#include "Edge.h"
#include "TNode.h"

namespace std {

    class MSTree
    {
    private:
        TNode ** A;
        int Alen;
        int weight;
    public:

        MSTree ( int n );
        ~MSTree( );
        void addEdge ( Edge e );
        TNode * getAList ( int n );
        void print( );
    };

} // std

#endif //SDIZO_2_MSTREE_H
