//
// Created by micha on 08.05.2023.
//

#ifndef SDIZO_2_EDGE_H
#define SDIZO_2_EDGE_H

    class Edge {
    public:
        int n1, n2, weight;
        bool operator == (const Edge& edge) const{
            return weight==edge.weight;
        }
        bool operator > (const Edge& edge) const{
            return weight>edge.weight;
        }
        bool operator < (const Edge& edge) const{
            return weight<edge.weight;
        }
    };


#endif //SDIZO_2_EDGE_H
