#include "headers/PQHeapMax.hpp"
#include "headers/PriorityQueue.hpp"
int main() {
    PQHeapMax pqHeap;
    pqHeap.insert(2, 10);
    pqHeap.insert(1, 10);
    pqHeap.insert(3, 15);
    pqHeap.modifyKey(3, 13);
    
    while (pqHeap.getSize() != 0) {
        PQHeapMax::Node node = pqHeap.extractMax();
        std::cout << "Element: " << node.element << " " << node.priority << std::endl;
    }
}