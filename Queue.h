//
// Created by micha on 01.06.2023.
//

#ifndef SDIZO_2_QUEUE_H
#define SDIZO_2_QUEUE_H


class Queue {
private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void push(int element);
    void pop();
    void empty();
    bool isEmpty();
    int first();
};


#endif //SDIZO_2_QUEUE_H
