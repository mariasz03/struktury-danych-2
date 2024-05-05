#include "../headers/PQHeapMax.hpp"

PQHeapMax::PQHeapMax(const PQHeapMax &other) : PriorityQueue(other) {}

void PQHeapMax::insert(uint32_t element, uint32_t priority) {
    if (size_ >= capacity_) { // Kiedy rozmiar jest wiekszy lub rowny pojemnosci, zwieksz dwukrotnie tablice
        resize();
    }
    // Wstawienie na koncu tablicy nowego elementu (na dole kopca)
    array_[size_].element = element;
    array_[size_].priority = priority;
    array_[size_].fifoPriority = size_ + 1; // Ustawienie priorytetu fifo na podstawie obecnej wielkosci tablicy
    heapifyUp(size_); // Reorganizacja kopca w gore od elementu
    size_++;
}

void PQHeapMax::insert(Node node) { // ^ to samo, ale gdy chcemy dodac juz caly wezel do kopca
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

    Node maxElement = array_[0]; // Pobranie korzenia kopca
    array_[0] = array_[size_-1]; // Ustawienie ostatniego elementu kopca jako korzen
    size_--; // Zmniejszenie wielkosci kopca
    heapifyDown(0); // Reorganizacja kopca w dol od korzenia - jezeli to potrzebne, przesuniecie go w dol
    return maxElement; // Zwrocenie najwiekszego elementu
}

PQHeapMax::Node PQHeapMax::peek() {
    if (size_ == 0) {
        throw std::runtime_error("Kopiec jest pusty.");
    }
    return array_[0]; // Zwrocenie korzenia
}

void PQHeapMax::modifyKey(uint32_t element, uint32_t priority)
{
    int index = -1;
    for (int i = 0; i < size_; i++) { // Liniowe przeszukanie tablicy kopca w poszukiwaniu elementu
        if (array_[i].element == element) {
            index = i;
        } 
    }
    if (index == -1) { 
        return; // Jezeli nie znaleziono elementu, zakoncz dzialanie metody
    }
    uint32_t oldPriority = array_[index].priority; // Pobranie starego priorytetu szukanego elementu
    array_[index].priority = priority; // Ustawienie nowego priorytetu wezlowi
    if (priority > oldPriority) { // Gdy nowy priorytet jest wiekszy od starego, zreorganizuj kopiec w gore od tego elementu
        heapifyUp(index);
    } else {
        heapifyDown(index); // W innym wypadku w dol
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
    while(index > 0 && array_[parent(index)] < array_[index]) { // Jezeli indeks rodzica jest mniejszy od indeksu elementu
        swap(parent(index), index); // Zamien wezel rodzica z wezlem elementu - przesuniecie wezla w gore
        index = parent(index); // Indeks elementu to teraz indeks rodzica
    }
}

void PQHeapMax::heapifyDown(int index) {
    int maxIndex = index; // Indeks elementu od ktorego przesuwamy w dol
    int leftChild = left(index); // Indeks lewego dziecka
    int rightChild = right(index); // Indeks prawego dziecka
    if (leftChild < size_ && array_[leftChild] > array_[maxIndex]) {
        maxIndex = leftChild; 
        // Jezeli lewe dziecko jest wieksze od elementu, ustaw indeks tego elementu jako najwiekszy indeks
    }
    if (rightChild < size_ && array_[rightChild] > array_[maxIndex]) {
        maxIndex = rightChild;
        // Jezeli prawe dziecko jest wieksze od elementu, ustaw indeks tego elementu jako najwiekszy indeks
    }
    if (index != maxIndex) {
        // Dopoki indeks elementu to nie ten najwiekszy, zamieniaj go z tym najwiekszym i powtarzaj rekurencyjnie
        swap(index, maxIndex);
        heapifyDown(maxIndex);
    }
}


