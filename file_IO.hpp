#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "headers/PriorityQueue.hpp"
// Funkcja zapisujaca strukture (container) w pliku (sciezka data/"filename") 
template<typename T>
void saveContainerToFile(T container, std::string filename) {
    std::ofstream outputFile("data/" + filename + ".csv");
    if (!outputFile.is_open()) {
        std::cerr << "Wystapil blad podczas proby otwarcia pliku.";
        return;
    }
    while (container.getSize() != 0) {
        PriorityQueue::Node currentNode = container.extractMax();
        outputFile << currentNode.element << ", " << currentNode.priority << std::endl;
    }
}
// Funkcja ladujaca do struktury (container) dane z pliku (sciezka data/"filename")
template<typename T>
void loadFileToContainer(T &container, std::string filename) {
    std::ifstream inputFile("data/" + filename + ".csv");
    if (!inputFile.is_open()) {
        std::cerr << "Wystapil blad podczas proby otwarcia pliku.";
        return;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        PriorityQueue::Node currentNode;
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ',');
        currentNode.element = std::stoul(token);
        std::getline(iss, token, ',');
        currentNode.priority = std::stoul(token);
        container.insert(currentNode);
    }
    inputFile.close();
}