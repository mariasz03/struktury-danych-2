#include "../headers/PQArrayMax.hpp"

void PQArrayMax::insert(uint32_t element, uint32_t priority) {  // Dodawanie elementu i jego priorytetu na koniec kolejki
    if (size_ == capacity_) {
        resize(); // Zwiększenie rozmiaru tablicy dwukrotnie
    }
    array_[size_].element = element; // Wstawienie elementu i jego priorytetu na końcu arraylist
    array_[size_].priority = priority;
    array_[size_].fifoPriority = size_ + 1; // Ustawienie priorytetu fifo na podstawie obecnej wielkosci tablicy 
    size_++;
}

void PQArrayMax::insert(Node node) {  // Dodawanie węzła na koniec kolejki
    if (size_ == capacity_) {
        resize(); 
    }
    array_[size_] = node;  // Wstawienie węzła na końcu arraylist
    array_[size_].fifoPriority = size_ + 1;
    size_++;
}

PQArrayMax::Node PQArrayMax::extractMax() {  // Usuwanie pierwszego elementu z kolejki o najwyższym priorytecie
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

PQArrayMax::Node PQArrayMax::peek() {  // Zwrócenie pierwszego elementu najwyższym priorytecie
    int maxIndex = findMaxIndex(); // Znalezienie indeksu elementu o najwiekszym priorytecie
    if (maxIndex == -1) {
        throw std::runtime_error("Tablica jest pusta.");
    }
    Node maxElement = array_[maxIndex];
    return maxElement; // Zwrócenie elementu o najwyższym priorytecie 
}

void PQArrayMax::modifyKey(uint32_t element, uint32_t newPriority) {  // Zmiana priorytetu pierwszego wystąpinia elementu
    for (int i = 0; i < size_; i++) {
        if (array_[i].element == element) {
            array_[i].priority = newPriority;
            break;
        }
    }
}

int PQArrayMax::findMaxIndex() const {  // Funkcja znajdująca największy indeks
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
