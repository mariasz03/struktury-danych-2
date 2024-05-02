#include <cstdint>
#include <iostream>
#include "headers/PQHeapMax.hpp"
#include "measure.hpp"
#include "file_IO.hpp"

int main() {
    int seed = 1;
    std::mt19937 gen(seed);
    int dataSetSize[14] = {5000, 10000, 50000, 100000, 250000, 500000, 750000, 1500000,
        2000000, 2500000, 5000000, 10000000, 20000000, 40000000};
    measureAndSave("INSERT", HEAPMAX, INSERT, 14, dataSetSize, seed, 1000);
}
