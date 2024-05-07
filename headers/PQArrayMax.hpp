#pragma once
#include "PriorityQueue.hpp"

struct Element {
    uint32_t value;
    uint32_t priority;
};

class ArrayList {
private:
    Element* array_;
    int initialCapacity_;
    int capacity_;
    int size_;

public:
    ArrayList(int initialCapacity = 10);
    ~ArrayList();
    void addLast(Element element);
    Element getElement(int index) const;
    void removeFrom(int index);
    int getSize() const;
    
};

class PQArrayMax : public PriorityQueue {
private:
    ArrayList array_;
    int findMaxIndex() const;

public:
    PQArrayMax(int capacity = 10);
    void insert(uint32_t element, uint32_t priority) override;
    void insert(Node node) override;
    Node extractMax() override;
    Node peek() override;
    void modifyKey(uint32_t element, uint32_t newPriority) override;
};
