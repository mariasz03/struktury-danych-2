#include "../headers/PQArrayMax.hpp"
#include <iostream>

ArrayList::ArrayList(int initialCapacity) : initialCapacity_(initialCapacity), capacity_(initialCapacity), size_(0) {
    array_ = new Element[capacity_];
}

ArrayList::~ArrayList() {
    delete[] array_;
}

void ArrayList::addLast(Element element) {
    if (size_ >= capacity_) {
        int newCapacity = capacity_ * 2;
        Element* newArray = new Element[newCapacity];
        for (int i = 0; i < size_; i++) {
            newArray[i] = array_[i];
        }
        delete[] array_;
        array_ = newArray;
        capacity_ = newCapacity;
    }
    array_[size_] = element;
    size_++;
}

Element ArrayList::getElement(int index) const {
    if (index < 0 || index >= size_) {
        std::cout<<"Index out of range.";
    }
    return array_[index];
}

void ArrayList::removeFrom(int index) {
    if (index < 0 || index >= size_) {
        std::cout<<"Index out of range.";
    }
    for (int i = index; i < size_ - 1; i++) {
        array_[i] = array_[i + 1];
    }
    size_--;
}

int ArrayList::getSize() const {
    return size_;
}
/////////////////
PQArrayMax::PQArrayMax(int capacity) : array_(capacity) {}

void PQArrayMax::insert(uint32_t element, uint32_t priority) {
    array_.addLast({element, priority});
}

void PQArrayMax::insert(Node node) {}

PQArrayMax::Node PQArrayMax::extractMax() {
    int maxIndex = findMaxIndex();
    if (maxIndex == -1) {
        throw std::runtime_error("Tablica jest pusta.");
    }
    Element maxElement = array_.getElement(maxIndex);
    array_.removeFrom(maxIndex);
    return Node{maxElement.value, maxElement.priority};
}

PQArrayMax::Node PQArrayMax::peek() {
    int maxIndex = findMaxIndex();
    if (maxIndex == -1) {
        throw std::runtime_error("Tablica jest pusta.");
    }
    Element maxElement = array_.getElement(maxIndex);
    return Node{maxElement.value, maxElement.priority};
}

void PQArrayMax::modifyKey(uint32_t element, uint32_t newPriority) {
    for (int i = 0; i < array_.getSize(); i++) {
        if (array_.getElement(i).value == element) {
            array_.removeFrom(i);
            array_.addLast({element, newPriority});
            break;
        }
    }
}

int PQArrayMax::findMaxIndex() const {
    if (array_.getSize() == 0) return -1;
    int maxIndex = 0;
    int maxPriority = array_.getElement(0).priority;
    for (int i = 1; i < array_.getSize(); i++) {
        if (array_.getElement(i).priority > maxPriority) {
            maxPriority = array_.getElement(i).priority;
            maxIndex = i;
        }
    }
    return maxIndex;
}
