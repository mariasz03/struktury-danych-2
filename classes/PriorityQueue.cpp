#include "../headers/PriorityQueue.hpp"

bool PriorityQueue::Node::operator<(Node const& other) {
    if (priority == other.priority) {
        return fifoPriority > other.fifoPriority;
    } else {
        return priority < other.priority;
    }
};

bool PriorityQueue::Node::operator>(Node const& other) {
    if (priority == other.priority) {
        return fifoPriority < other.fifoPriority;
    } else {
        return priority > other.priority;
    }
};

PriorityQueue::PriorityQueue() : size_(0), capacity_(0) {
    array_ = new Node[capacity_];
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

void PriorityQueue::swap(int index1, int index2) {
    Node temp;
    temp = array_[index1];
    array_[index1] = array_[index2];
    array_[index2] = temp;
};

void PriorityQueue::resize() {
    int newCapacity = capacity_ * 2;
    Node* newArray = new Node[newCapacity];

    for (int i = 0; i < size_; i++) {
        newArray[i] = array_[i];
    }
    delete[] array_;
    array_ = newArray;
    capacity_ = newCapacity;
}

