#pragma once
#include <cstdint>
#include <stdint.h>

class PriorityQueue {
protected:
    struct Node {
        uint32_t element;
        int priority;
    };
    Node *array_;
    int size_;
    int capacity_;
    void resize();
public:
    PriorityQueue();
    virtual ~PriorityQueue();
    virtual void insert(uint32_t element, int priority) = 0;
    virtual uint32_t extractMax() = 0;
    virtual uint32_t peek() = 0;
    virtual void modifyKey(uint32_t element, int priority) = 0;
    int getSize() const;
    int getCapacity() const;
    void swap(int index1, int index2);

};