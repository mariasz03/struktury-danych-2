#include "headers/PQHeapMax.hpp"
#include "headers/PriorityQueue.hpp"
int main() {
    PQHeapMax pqHeap;
    for (int i = 0; i < 100; i++) {
        pqHeap.insert(i, i);
    }
    
    while (pqHeap.getSize() != 0) {
        std::cout << "Element: " << pqHeap.extractMax() << std::endl;
    }
}