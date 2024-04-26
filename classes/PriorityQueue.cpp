#include "../headers/PriorityQueue.hpp"

PriorityQueue::PriorityQueue(int capacity) : size_(0), capacity_(capacity) {
    array_ = new uint32_t[capacity];
};

PriorityQueue::~PriorityQueue() {
    delete[] array_;
}

int PriorityQueue::getSize() const {
    return size_;
};

int PriorityQueue::getCapacity() const {
    return capacity_;
};
