#pragma once
#include <iostream>
#include "PriorityQueue.hpp"

class PQArrayMax : public PriorityQueue {
private:
    int findMaxIndex() const;  //funkcja znajdująca największy indeks
public:
    PQArrayMax() : PriorityQueue() {};
    void insert(uint32_t element, uint32_t priority) override;  //dodawanie elementu o priorytecie na koniec kolejki
    void insert(Node node) override;  //dodawanie węzła na koniec kolejki
    Node extractMax() override;  //usuwanie elementu z kolejki o pierwszym najwyższym priorytecie
    Node peek() override;  //zwrócenie elementu o pierwszym najwyższym priorytecie
    void modifyKey(uint32_t element, uint32_t newPriority) override;  //zmiana priorytetu pierwszego wystąpinia elementu
};
