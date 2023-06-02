//
// Created by micha on 01.06.2023.
//

#include <cstdint>
#include "Queue.h"

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

Queue::~Queue() {
    empty();
}

void Queue::push(int element) {
    Node* node = new Node;
    node->data = element;
    node->next = nullptr;
    if(tail){
        tail->next = node;
    }else head = node;
    tail = node;
}

void Queue::pop() {
    if(head){
        auto temp = head;
        head = head->next;
        if(!head) tail = nullptr;
        delete temp;
    }
}

void Queue::empty() {
    while (head) pop();
}

bool Queue::isEmpty() {
    return !head;
}

int Queue::first() {
    if(head) return head->data;
    return INT32_MIN;
}
