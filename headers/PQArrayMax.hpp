#pragma once
#include "PriorityQueue.hpp"

class PQArrayMax : private PriorityQueue {
public:
    PQArrayMax(int capacity = 0);
    void insert(uint32_t element, int priority) override;
    uint32_t extractMax() override;
    uint32_t peek() override;
    void modifyKey(uint32_t element, int priority) override;
};