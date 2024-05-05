#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "headers/PriorityQueue.hpp"
#include "headers/PQArrayMax.hpp"
#include "headers/PQHeapMax.hpp"
#include "headers/Timer.hpp"
#include "generate_data.hpp"
enum Function {
    INSERT,
    EXTRACT_MAX,
    PEEK,
    MODIFY_KEY,
    RETURN_SIZE    
};

enum PriorityQueueType {
    HEAPMAX,
    ARRAYMAX
};

template<typename T>
double measure(T container, Function func, uint32_t number = 0, uint32_t priority = 0) { 
    Timer timer;
    switch (func) {
        case INSERT:
            container.insert(number, priority);
            break;
        case EXTRACT_MAX:
            container.extractMax();
            break;
        case PEEK:
            container.peek();
            break;
        case MODIFY_KEY:
            container.modifyKey(number, priority);
            break;
        case RETURN_SIZE :
            container.getSize();
            break;      
    }
    return timer.elapsed();
};

template<typename T>
double measureAverage(T container, Function func, int repetitions, uint32_t number = 0, uint32_t priority = 0) {
    double avg;
    double sum = 0;
    for (int i = 0; i < repetitions; i++) {
        sum += measure(container, func, number, priority);
    }
    avg = sum / repetitions;
    return avg;
};

void measureAndSave(std::string filename, PriorityQueueType pqType, Function func, int numberOfDataSets, int dataSetSize[], int numberOfSeeds, int seed[], int repetitions, uint32_t number[] = 0, uint32_t priority[] = 0) {
    std::ofstream outputFile("measured/" + filename + ".csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error occurred while opening file.";
        return;
    }
        
    for (int i = 0; i < numberOfDataSets; i++) {
        double totalTime = 0; 
        for (int j = 0; j < numberOfSeeds; j++) {
            double time = 0; 
            switch (pqType) {
                case HEAPMAX: {
                    PQHeapMax container; 
                    fillContainerWithRandomData(container, dataSetSize[i], seed[j]);
                    time = measureAverage(container, func, repetitions, number[j], priority[j]);
                    break;
                }
                case ARRAYMAX: {
                    break;
                }
            }
            totalTime += time;
        }
        double avgTime = totalTime / numberOfSeeds;
        outputFile << dataSetSize[i] << ", " << avgTime << std::endl;
    }

    outputFile.close();
}