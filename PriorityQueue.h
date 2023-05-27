//
// Created by micha on 08.05.2023.
//

#ifndef SDIZO_2_PRIORITYQUEUE_H
#define SDIZO_2_PRIORITYQUEUE_H

#include "Edge.h"

namespace std {
    template <class T>
    class PriorityQueue {

    private:
        T* heap;
        int allocatedSize;
        static inline void swap(T* a,T* b);
        void heapify(int i);
    public:
        int size;
        explicit PriorityQueue(int size);
        ~PriorityQueue();
        void deleteMinimum();
        void insert(T element);
        T minimum();
    };

} // std

#endif //SDIZO_2_PRIORITYQUEUE_H
