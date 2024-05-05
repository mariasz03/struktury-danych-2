#include "../headers/PriorityQueue.hpp"

bool PriorityQueue::Node::operator<(Node const& other) {
    if (priority == other.priority) {
        return fifoPriority > other.fifoPriority;
    } else {
        return priority < other.priority;
    }
}

bool PriorityQueue::Node::operator>(Node const& other) {
    if (priority == other.priority) {
        return fifoPriority < other.fifoPriority;
    } else {
        return priority > other.priority;
    }
}

PriorityQueue::PriorityQueue() : size_(0), capacity_(10) {
    array_ = new Node[capacity_];
}

PriorityQueue::PriorityQueue(const PriorityQueue &other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    array_ = new Node[capacity_];
    for (int i = 0; i < size_; ++i) {
        array_[i] = other.array_[i];
    }
}

PriorityQueue::~PriorityQueue() {
    delete[] array_;
}

int PriorityQueue::getSize() const {
    return size_;
}

int PriorityQueue::getCapacity() const {
    return capacity_;
}

void PriorityQueue::swap(int index1, int index2) {
    Node temp;
    temp = array_[index1];
    array_[index1] = array_[index2];
    array_[index2] = temp;
}

uint32_t PriorityQueue::getRandomValue() {
    int index = rand() % size_;
    return array_[index].element;
}

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

