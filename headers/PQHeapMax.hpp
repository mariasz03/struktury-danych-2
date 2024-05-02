#pragma once
#include "PriorityQueue.hpp"
#include <iostream>

class PQHeapMax : public PriorityQueue {
public:
    PQHeapMax() : PriorityQueue() {};
    PQHeapMax(const PQHeapMax &other); // Konstruktor kopiujący
    void insert(uint32_t element, int priority) override;
    void insert(Node node) override;
    Node extractMax() override;
    Node peek() override;
    void modifyKey(uint32_t element, int priority) override;
private:
    int parent(int index);
    int left(int index);
    int right(int index);
    void heapifyUp(int index);
    void heapifyDown(int index);
};