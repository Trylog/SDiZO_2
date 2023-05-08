//
// Created by micha on 08.05.2023.
//

#include "GraphMatrix.h"

namespace std {
    GraphMatrix::GraphMatrix(int v) {
        this->v=v;
        matrix = new int*[v];
        for (int i = 0; i < v; ++i) {
            matrix[i] = new int[v];
            for (int j = 0; j < v; ++j) matrix[i][j]=0;
        }
    }

    GraphMatrix::~GraphMatrix() {
        for (int i = 0; i < v; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void GraphMatrix::insert(Edge edge) {
        matrix[edge.n1][edge.n2]=edge.weight;
    }

    void GraphMatrix::display() {//TODO wyświetlanie grafu

    }
} // std