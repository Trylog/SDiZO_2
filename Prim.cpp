//
// Created by micha on 18.05.2023.
//

#include <fstream>
#include "Prim.h"

namespace std {
    void Prim::buildFromFile(string filePath, MSTree &output, int &v, int &e, int &wStart) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()) {
            input >> e;
            input >> v;
            input >> wStart;
            if (e) {
                Edge tempIn;
                for (auto i = 0; i < e; ++i) {
                    if (!input.eof()) {
                        input >> tempIn.n1;
                        input >> tempIn.n2;
                        input >> tempIn.weight;
                        output.addEdge(tempIn);
                    } else throw -3; //wrong file length
                }
            }
        }

    }
} // std