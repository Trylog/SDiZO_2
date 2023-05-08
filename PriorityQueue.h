//
// Created by micha on 08.05.2023.
//

#ifndef SDIZO_2_PRIORITYQUEUE_H
#define SDIZO_2_PRIORITYQUEUE_H

#include "Edge.h"

namespace std {

    class PriorityQueue {

    private:
        Edge* heap;
        int size, allocatedSize;
        static inline void swap(Edge* a,Edge* b);
        void heapify(int i);
    public:
        explicit PriorityQueue(int size);
        ~PriorityQueue();
        void deleteMinimum();
        void insert(Edge edge);
        Edge minimum();
    };

} // std

#endif //SDIZO_2_PRIORITYQUEUE_H
