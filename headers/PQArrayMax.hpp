#pragma once
#include "PriorityQueue.hpp"

class PQArrayMax : public PriorityQueue {
public:
    PQArrayMax() : PriorityQueue() {};
    PQArrayMax(const PQArrayMax &other); // Konstruktor kopiujący
    void insert(uint32_t element, uint32_t priority) override;
    Node extractMax() override;
    Node peek() override;
    void modifyKey(uint32_t element, uint32_t priority) override;
};