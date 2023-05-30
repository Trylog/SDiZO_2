//
// Created by micha on 08.05.2023.
//

#ifndef SDIZO_2_GRAPHMATRIX_H
#define SDIZO_2_GRAPHMATRIX_H

#include "Edge.h"

namespace std {

    class GraphMatrix {
        int v; //liczba wierzchołków
    public:
        int** matrix;
        explicit GraphMatrix(int v);
        ~GraphMatrix();
        void insert(Edge edge);
        void display();
    };

} // std

#endif //SDIZO_2_GRAPHMATRIX_H
