#pragma once
#include "PriorityQueue.hpp"

class PQHeapMax : private PriorityQueue {
public:
    PQHeapMax(int capacity = 0); // Konstruktor - tworzy kopiec o podanej pojemnosci
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