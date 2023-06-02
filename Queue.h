//
// Created by micha on 01.06.2023.
//

#ifndef SDIZO_2_QUEUE_H
#define SDIZO_2_QUEUE_H


class Queue {
private:
    struct node{
        int data;
        node* next;
    };
    node* head;
    node* tail;
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
