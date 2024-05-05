#include <chrono>
#include <cstdint>
#include <iostream>
#include <limits>
#include "headers/PQHeapMax.hpp"
#include "measure.hpp"
#include "file_IO.hpp"

int main() {
    srand(time(NULL));
    int seeds[5];
    for (int i = 0; i < 5; i++) {
        seeds[i] = rand();
    }
    uint32_t element[5];
    uint32_t priority[5];
    for (int i = 0; i < 5; i++) {
        std::mt19937 gen(seeds[i]);
        element[i] = generateRandomNumberFromSeed(gen);
        priority[i] = generateRandomNumberFromSeed(gen);
        std::cout << element[i] << " " << priority[i] << std::endl;
    }
    int dataSetSize[10] = {1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000};
    measureAndSave("HEAP_INSERT", HEAPMAX, INSERT, 10, dataSetSize, 5, seeds, 100, element, priority);
    measureAndSave("HEAP_EXTRACTMAX", HEAPMAX, EXTRACT_MAX, 10, dataSetSize, 5, seeds, 100, element, priority);
    measureAndSave("HEAP_PEEK", HEAPMAX, PEEK, 10, dataSetSize, 5, seeds, 100, element, priority);
    measureAndSave("HEAP_MODIFYKEY", HEAPMAX, MODIFY_KEY, 10, dataSetSize, 5, seeds, 100, element, priority);
    measureAndSave("HEAP_RETURNSIZE", HEAPMAX, RETURN_SIZE, 10, dataSetSize, 5, seeds, 100, element, priority);
}
