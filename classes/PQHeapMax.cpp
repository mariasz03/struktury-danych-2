#include "../headers/PQHeapMax.hpp"

void PQHeapMax::insert(uint32_t element, int priority) {
    if (size_ == capacity_) {
        resize();
    }

    array_[size_].element = element;
    array_[size_].priority = priority;
    heapifyUp(size_);
    size_++;
}

uint32_t PQHeapMax::extractMax() { // TODO: Zaimplementowac kopiec tak, aby przy wywolaniu funkcji extractMax, peek zwracany byl wezel (element + priorytet)
// a nie tylko element
    if (size_ == 0) {
        std::cout << "Heap is empty!" << std::endl;
    }

    uint32_t maxElement = array_[0].element;
    array_[0] = array_[size_-1];
    size_--;
    heapifyDown(0);
    return maxElement;
}

uint32_t PQHeapMax::peek() {
    if (size_ == 0) {
        return 0;
    }

    return array_[0].element;
}

void PQHeapMax::modifyKey(uint32_t element, int priority) // TODO: Zaimplementowac funkcje modifyKey()
{
    std::cout << ".";
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
    while(index > 0 && array_[parent(index)].priority < array_[index].priority) {
        swap(parent(index), index);
        index = parent(index);
    }
}

void PQHeapMax::heapifyDown(int index) {
    int maxIndex = index;
    int leftChild = left(index);
    int rightChild = right(index);
    if (leftChild < size_ && array_[leftChild].priority > array_[maxIndex].priority) {
        maxIndex = leftChild;
    }
    if (rightChild < size_ && array_[rightChild].priority > array_[maxIndex].priority) {
        maxIndex = rightChild;
    }
    if (index != maxIndex) {
        swap(index, maxIndex);
        heapifyDown(maxIndex);
    }
}


