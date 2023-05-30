//
// Created by micha on 08.05.2023.
//

#include "PriorityQueue.h"

namespace std {
    inline void PriorityQueue::swap(Edge* a, Edge* b)
    {
        auto temp = *b;
        *b = *a;
        *a = temp;
    }

    void PriorityQueue::heapify(int i) {
        int smallest;
        while(true){
            auto left = i*2+1;
            auto right = i*2+2;
            if(left < size && heap[left].weight < heap[i].weight){
                smallest = left;
            }else smallest = i;
            if(right < size && heap[right].weight < heap[smallest].weight) smallest = right;
            if(smallest != i){swap(&heap[i], &heap[smallest]);
            } else break;
            i = smallest;
        }
    }

    void PriorityQueue::deleteMinimum() {

        auto temp = new Edge[size-1];
        swap(&heap[0], &heap[size-1]);
        size--;
        for (int i = size / 2 - 1; i >= 0; i--)heapify(i);

        /*for (int i = 1; i < size; ++i)temp[i]=heap[i+1];
        delete[] heap;
        heap=temp;*/
    }

    void PriorityQueue::insert(Edge edge) {
        if(size==allocatedSize){
            auto temp = new Edge[size+1];
            for (int i = 0; i < size; ++i) {
                temp[i]=heap[i];
            }
            delete[] heap;
            heap=temp;
        }
        heap[size]=edge;
        for(int i = size; heap[(i-1)/2].weight>heap[i].weight&&i!=0;i=(i-1)/2) {
            swap(&heap[i], &heap[(i-1)/2]);
        }
        size++;
    }

    Edge PriorityQueue::minimum() {
        return heap[0];
    }

    PriorityQueue::PriorityQueue(int size) {
        allocatedSize = size;
        heap = new Edge[size];
        this->size = 0;
    }

    PriorityQueue::~PriorityQueue() {
        delete[] heap;
    }
} // std