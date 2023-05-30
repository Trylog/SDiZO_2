//
// Created by micha on 16.05.2023.
//
#include <iostream>
#include "MSTree.h"
#include "TNode.h"

namespace std {

    MSTree::MSTree ( int n ){
        int i;
        A = new TNode * [ n ];
        for( i = 0; i < n; i++ ) A [ i ] = nullptr;
        Alen = n - 1;
    }

    MSTree::~MSTree( ){
        int i;
        TNode *p, *r;
        for( i = 0; i <= Alen; i++ ){
            p = A [ i ];
            while( p ){
                r = p;
                p = p->next;
                delete r;
            }
        }
        delete [] A;
    }

    void MSTree::addEdge ( Edge e ){
        TNode *p;
        //weight += e.weight;
        p = new TNode;
        p->v = e.n2;
        p->weight = e.weight;
        p->next = A [e.n1];
        A [e.n1] = p;

        p = new TNode;
        p->v = e.n1;
        p->weight = e.weight;
        p->next = A [ e.n2 ];
        A [ e.n2 ] = p;
    }

    TNode * MSTree::getAList ( int n ){
        return A [ n ];
    }

    void MSTree::print( ){
        int i;
        TNode *p;
        weight=0;
        cout << endl;
        for( i = 0; i <= Alen; i++ ){
            cout << "Vertex " << i << " - ";
            for( p = A [ i ]; p; p = p->next ){
                cout << p->v << ":" << p->weight << " ";
                weight+=p->weight;
            }
            cout << endl;
        }
        cout << endl << endl << "Minimal Spanning Tree Weight = " << weight/2 << endl << endl;
    }
} // std