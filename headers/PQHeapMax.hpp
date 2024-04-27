#pragma once
#include "PriorityQueue.hpp"
#include <iostream>

class PQHeapMax : public PriorityQueue {
public:
    PQHeapMax() : PriorityQueue() {};
    void insert(uint32_t element, int priority) override;
    uint32_t extractMax() override;
    uint32_t peek() override;
    void modifyKey(uint32_t element, int priority) override;
private:
    int parent(int index);
    int left(int index);
    int right(int index);
    void heapifyUp(int index);
    void heapifyDown(int index);
};