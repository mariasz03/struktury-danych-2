#pragma once
#include <iostream>
#include "PriorityQueue.hpp"

class PQArrayMax : public PriorityQueue {
private:
    int findMaxIndex() const;
public:
    PQArrayMax() : PriorityQueue() {};
    void insert(uint32_t element, uint32_t priority) override;
    void insert(Node node) override;
    Node extractMax() override;
    Node peek() override;
    void modifyKey(uint32_t element, uint32_t newPriority) override;
};
