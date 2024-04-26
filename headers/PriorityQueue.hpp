#pragma once
#include <stdint.h>

class PriorityQueue {
public:
    PriorityQueue(int capacity = 0);
    ~PriorityQueue();
    virtual void insert(uint32_t element, int priority);
    virtual uint32_t extractMax();
    virtual uint32_t peek();
    virtual void modifyKey(uint32_t element, int priority);
    int getSize() const;
    int getCapacity() const;
protected:
    uint32_t *array_;
    int size_;
    int capacity_;
};