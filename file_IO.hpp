#include <fstream>

#include "headers/PriorityQueue.hpp"

template<typename T>
void saveContainerToFile(T container, std::string filename) {
    std::ofstream output;
    output.open("data/" + filename + ".csv");
    while (container.getSize() != 0) {
        PriorityQueue::Node currentNode = container.extractMax();
        output << currentNode.element << ", " << currentNode.priority << std::endl;
    }
}

template<typename T>
void loadFileToContainer(T container, std::string filename) { // TODO Napisać funkcje ladujaca z pliku do struktury
}