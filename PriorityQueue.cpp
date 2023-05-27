//
// Created by micha on 08.05.2023.
//

#include "PriorityQueue.h"

namespace std {

    template <class T>
    inline void PriorityQueue<T>::swap(T* a, T* b)
    {
        auto temp = *b;
        *b = *a;
        *a = temp;
    }

    template <class T>
    void PriorityQueue<T>::heapify(int i) {
        int smallest;
        while(true){
            auto left = i*2+1;
            auto right = i*2+2;
            if(left < size && heap[left] < heap[i]){
                smallest = left;
            }else smallest = i;
            if(right < size && heap[right] < heap[smallest]) smallest = right;
            if(smallest != i){swap(&heap[i], &heap[smallest]);
            } else break;
            i = smallest;
        }
    }

    template <class T>
    void PriorityQueue<T>::deleteMinimum() {

        auto temp = new Edge[size-1];
        swap(&heap[0], &heap[size-1]);
        size--;
        for (int i = size / 2 - 1; i >= 0; i--)heapify(i);

        /*for (int i = 1; i < size; ++i)temp[i]=heap[i+1];
        delete[] heap;
        heap=temp;*/
    }

    template <class T>
    void PriorityQueue<T>::insert(T element) {
        if(size==allocatedSize){
            auto temp = new T[size+1];
            for (int i = 0; i < size; ++i) {
                temp[i]=heap[i];
            }
            delete[] heap;
            heap=temp;
        }
        heap[size]=element;
        for(int i = size; heap[(i-1)/2]>heap[i]&&i!=0;i=(i-1)/2) {
            swap(&heap[i], &heap[(i-1)/2]);
        }
        size++;
    }

    template <class T>
    T PriorityQueue<T>::minimum() {
        return heap[0];
    }

    template <class T>
    PriorityQueue<T>::PriorityQueue(int size) {
        allocatedSize = size;
        heap = new T[size];
        this->size = 0;
    }

    template <class T>
    PriorityQueue<T>::~PriorityQueue() {
        delete[] heap;
    }
} // std