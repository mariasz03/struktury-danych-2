#pragma once
#include "PriorityQueue.hpp"
#include <iostream>

class PQHeapMax : public PriorityQueue {
public:
    PQHeapMax() : PriorityQueue() {};
    PQHeapMax(const PQHeapMax &other); // Konstruktor kopiujący kopiec podana w argumencie
    void insert(uint32_t element, uint32_t priority) override;
    void insert(Node node) override;
    Node extractMax() override;
    Node peek() override;
    void modifyKey(uint32_t element, uint32_t priority) override;
private:
    int parent(int index); // Zwraca indeks rodzica wezlu nad
    int left(int index); // Zwraca lewy indeks wezla pod
    int right(int index); // Zwraca prawy indeks wezla pod
    // Funkcja reorganizujaca strukutre kopca, po dodaniu nowego elementu przesuwa ten element w gore drzewa, 
    // az do momentu gdy zachowana zostanie wlasnosc kopca (najwiekszy element z przodu)
    void heapifyUp(int index); 
    // Funkcja reorganizujaca strukutre kopca, po usunieciu elementu, gdy ostatni element jest wstawiany jako korzen i
    // istnieje potrzeba jego przesunieciecia w dol
    void heapifyDown(int index);
};