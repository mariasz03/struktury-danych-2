#include "../headers/PQHeapMax.hpp"

PQHeapMax::PQHeapMax(const PQHeapMax &other) : PriorityQueue(other) {}

void PQHeapMax::insert(uint32_t element, uint32_t priority) {
    if (size_ >= capacity_) {
        resize();
    }

    array_[size_].element = element;
    array_[size_].priority = priority;
    array_[size_].fifoPriority = size_ + 1;
    heapifyUp(size_);
    size_++;
}

void PQHeapMax::insert(Node node) {
    if (size_ == capacity_) {
        resize();
    }

    array_[size_] = node;
    array_[size_].fifoPriority = size_ + 1;
    heapifyUp(size_);
    size_++;
}


PQHeapMax::Node PQHeapMax::extractMax() { 
    if (size_ == 0) {
        throw std::runtime_error("Kopiec jest pusty.");
    }

    Node maxElement = array_[0];
    array_[0] = array_[size_-1];
    size_--;
    heapifyDown(0);
    return maxElement;
}

PQHeapMax::Node PQHeapMax::peek() {
    if (size_ == 0) {
        throw std::runtime_error("Kopiec jest pusty.");
    }
    return array_[0];
}

void PQHeapMax::modifyKey(uint32_t element, uint32_t priority)
{
    int index = -1;
    for (int i = 0; i < size_; i++) {
        if (array_[i].element == element) {
            index = i;
        } 
    }
    if (index == -1) {
        return;
    }
    uint32_t oldPriority = array_[index].priority;
    array_[index].priority = priority;
    if (priority > oldPriority) {
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

int PQHeapMax::parent(int index) {
    return (index - 1) / 2;
}

int PQHeapMax::left(int index) {
    return 2 * index + 1;
}

int PQHeapMax::right(int index) {
    return 2 * index + 2;
}

void PQHeapMax::heapifyUp(int index) {
    while(index > 0 && array_[parent(index)] < array_[index]) {
        swap(parent(index), index);
        index = parent(index);
    }
}

void PQHeapMax::heapifyDown(int index) {
    int maxIndex = index;
    int leftChild = left(index);
    int rightChild = right(index);
    if (leftChild < size_ && array_[leftChild] > array_[maxIndex]) {
        maxIndex = leftChild;
    }
    if (rightChild < size_ && array_[rightChild] > array_[maxIndex]) {
        maxIndex = rightChild;
    }
    if (index != maxIndex) {
        swap(index, maxIndex);
        heapifyDown(maxIndex);
    }
}


