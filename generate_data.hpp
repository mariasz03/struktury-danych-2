#include <cstdint>
#include <random>

#include "headers/PriorityQueue.hpp"

uint32_t generateRandomNumberFromSeed(std::mt19937 &gen) { 
    std::uniform_int_distribution<uint32_t> dis(0, std::numeric_limits<uint32_t>::max());
    return dis(gen);
}

template<typename T>
void fillContainerWithRandomData(T& container, int amountOfData, int seed) {
    std::mt19937 gen(seed);
    for (int i = 0; i < amountOfData; i++) {
        container.insert(generateRandomNumberFromSeed(gen), generateRandomNumberFromSeed(gen));
    }
}