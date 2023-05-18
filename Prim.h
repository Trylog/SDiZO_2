//
// Created by micha on 18.05.2023.
//

#ifndef SDIZO_2_PRIM_H
#define SDIZO_2_PRIM_H

#include <string>
#include "MSTree.h"

namespace std {

    class Prim {

    public:
        static void buildFromFile(string fileName, MSTree &output, int &v, int &e, int &wStart);
    };

} // std

#endif //SDIZO_2_PRIM_H
