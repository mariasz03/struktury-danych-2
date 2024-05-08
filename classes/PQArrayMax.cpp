#include "../headers/PQArrayMax.hpp"

void PQArrayMax::insert(uint32_t element, uint32_t priority) {
    if (size_ == capacity_) {
        resize(); // Zwiększenie rozmiaru tablicy dwukrotnie
    }
    array_[size_].element = element; // Wstawienie elementu na końcu arraylist
    array_[size_].priority = priority;
    array_[size_].fifoPriority = size_ + 1; // Ustawienie priorytetu fifo na podstawie obecnej wielkosci tablicy 
    size_++;
}

void PQArrayMax::insert(Node node) {
    if (size_ == capacity_) {
        resize(); 
    }
    array_[size_] = node;
    array_[size_].fifoPriority = size_ + 1;
    size_++;
}

PQArrayMax::Node PQArrayMax::extractMax() {
    int maxIndex = findMaxIndex(); // Znalezienie indeksu elementu o najwiekszym priorytecie
    if (maxIndex == -1) {
        throw std::runtime_error("Tablica jest pusta.");
    }
    Node maxElement = array_[maxIndex]; 
    if (size_ - 1 <= capacity_ / 2 && capacity_ > 10) { // Usuniecie najwiekszego elementu oraz przesuniecie elementow w tablicy
        capacity_ /= 2;
        Node *newArray = new Node[capacity_];
        for (int i = 0, j = 0; i < size_; i++) {
            if (i != maxIndex) {
                newArray[j++] = array_[i];
            }
        }
        delete[] array_;
        array_ = newArray;
    } else {
        for (int i = maxIndex; i < size_ - 1; i++) {
            array_[i] = array_[i + 1];
        }
    }
    size_--;
    return maxElement;
}

PQArrayMax::Node PQArrayMax::peek() {
    int maxIndex = findMaxIndex();
    if (maxIndex == -1) {
        throw std::runtime_error("Tablica jest pusta.");
    }
    Node maxElement = array_[maxIndex];
    return maxElement;
}

void PQArrayMax::modifyKey(uint32_t element, uint32_t newPriority) {
    for (int i = 0; i < size_; i++) {
        if (array_[i].element == element) {
            array_[i].priority = newPriority;
            break;
        }
    }
}

int PQArrayMax::findMaxIndex() const {
    if (size_ == 0) return -1;
    int maxIndex = 0;
    int maxPriority = array_[0].priority;
    for (int i = 0; i < size_; i++) { // Liniowe przejscie przez cala tablice w celu znalezienia najwiekszego indeksu
        if (array_[i].priority > maxPriority) {
            if (array_[i].priority > maxPriority || (array_[i].priority == maxPriority && array_[i].fifoPriority < array_[maxIndex].fifoPriority)) {
                maxPriority = array_[i].priority;
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}
