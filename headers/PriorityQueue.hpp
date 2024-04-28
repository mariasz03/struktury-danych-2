#pragma once
#include <cstdint>
#include <stdint.h>

class PriorityQueue {
public:
    struct Node {
        uint32_t element;
        int priority;
        int fifoPriority;
        bool operator<(Node const& other);
        bool operator>(Node const& other);
    };
    PriorityQueue();
    virtual ~PriorityQueue();
    virtual void insert(uint32_t element, int priority) = 0;
    virtual Node extractMax() = 0;
    virtual Node peek() = 0;
    virtual void modifyKey(uint32_t element, int priority) = 0;
    int getSize() const;
    int getCapacity() const;
    void swap(int index1, int index2);
protected:
    Node *array_;
    int size_;
    int capacity_;
    void resize();
};