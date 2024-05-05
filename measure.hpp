#include <iostream>
#include <fstream>
#include <string>

#include "headers/PQArrayMax.hpp"
#include "headers/PQHeapMax.hpp"
#include "headers/Timer.hpp"
#include "generate_data.hpp"
enum Function { // Funkcje ktore mozna zbadac
    INSERT,
    EXTRACT_MAX,
    PEEK,
    MODIFY_KEY,
    RETURN_SIZE    
};

enum PriorityQueueType { // Rodzaje implementacji kolejki ktore mozna zbadac
    HEAPMAX,
    ARRAYMAX
};
// Funkcja wykonujaca pojedynczy pomiar metody (func) kolejki (container). number i priority to liczby ktore sa potrzebne do
// wykonania operacji insert i modifyKey. Zwraca czas wykonania operacji w nanosekundach.
template<typename T>
double measure(T container, Function func, uint32_t number = 0, uint32_t priority = 0) { 
    Timer timer;
    switch (func) {
        case INSERT:
            container.insert(number, priority);
            std::cout << number << " " << priority;
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
        case RETURN_SIZE:
            container.getSize();
            break;      
    }
    return timer.elapsed();
};


// Funkcja mierzaca dana operacje podana liczbe razy (repetitions) i usredniajaca ten pomiar
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

// Funkcja dla na podstawie ziaren (seed) generuje rozne rozmiary struktur (dataSetSize) oraz mierzy podana metode kolejki.
// Metoda na pojedynczym zestawie danych jest wykonywana repetitions razy i usredniana.
// Wyniki ze wszystkich ziaren dla kazdej operacji sa usredniane
// Wyniki zapisywane sa w pliku o sciezce measured/"file".csv
void measureAndSave(std::string filename, PriorityQueueType pqType, Function func, int numberOfDataSets, int dataSetSize[], int numberOfSeeds, int seed[], int repetitions, uint32_t number[] = 0, uint32_t priority[] = 0) {
    std::ofstream outputFile("measured/" + filename + ".csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error occurred while opening file.";
        return;
    }
    for (int i = 0; i < numberOfDataSets; i++) {
        double totalTime = 0; // Czas operacji zsumowany z kazdego ziarna
        for (int j = 0; j < numberOfSeeds; j++) {
            double time = 0; // Sredni czas pojedynczej operacji
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
        double avgTime = totalTime / numberOfSeeds; // Wynik usredniony z wszystkich ziaren
        outputFile << dataSetSize[i] << ", " << avgTime << std::endl;
    }
    outputFile.close();
}