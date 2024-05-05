#pragma once
#include <cstdint>
#include <stdint.h>
#include <random>

class PriorityQueue {
public:
    struct Node {
        uint32_t element; // Element, wartosc wezla
        uint32_t priority; // Priorytet elementu
        uint32_t fifoPriority; // Priorytet fifo - uzywany w przypadku gdy elementy maja ten sam priorytet
        bool operator<(Node const& other); // Operatory porownania wezla - na podstawie priorytetu
        bool operator>(Node const& other);
    };
    PriorityQueue();
    PriorityQueue(const PriorityQueue &other);
    ~PriorityQueue();
    virtual void insert(uint32_t element, uint32_t priority) = 0; // Funkcja tworzaca i dodajaca wezel do kolejki
    virtual void insert(Node node) = 0;
    virtual Node extractMax() = 0; // Funkcja ktora zwraca oraz usuwa pierwszy element z kolejki - o najwyzszym priorytecie
    virtual Node peek() = 0; // Funkcja ktora zwraca pierwszy element z kolejki - o najwyzszym priorytecie
    virtual void modifyKey(uint32_t element, uint32_t priority) = 0; // Funkcja ktora znajduje w kolejce element oraz zmienia jego priorytet
    int getSize() const; // Zwraca rozmiar kolejki
    int getCapacity() const; // Zwraca pojemnosc tablicy, na ktorej zaimplementowany jest kopiec
    void swap(int index1, int index2); // Zamienia elementy w tablicy na podanych indeksach
    uint32_t getRandomValue(); // Zwraca losowa wartosc z tablicy
protected:
    Node *array_;
    int size_;
    int capacity_;
    void resize(); // Funkcja zwiekszajaca rozmiar tablicy (dwukrotnie)
};