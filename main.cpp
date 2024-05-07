#include <cstdint>
#include <iostream>

#include "headers/PQHeapMax.hpp"
#include "headers/PriorityQueue.hpp"
#include "headers/PQArrayMax.hpp"
#include "measure.hpp"
#include "file_IO.hpp"

template <typename T>
void performOperations(T& pq) {
    int operationMenu;
    uint32_t element, priority;
    while (true) {
        std::cout << std::endl << "Wybierz operacje: " << std::endl;
        std::cout << "1. Dodaj element do kolejki." << std::endl; 
        std::cout << "2. Pobierz najwiekszy element z kolejki." << std::endl; 
        std::cout << "3. Pokaz najwiekszy element z kolejki." << std::endl; 
        std::cout << "4. Zmien priorytet elementu." << std::endl; 
        std::cout << "5. Pokaz rozmiar kolejki." << std::endl; 
        std::cout << "6. Zapisz kolejke do pliku." << std::endl; 
        std::cout << "7. Wczytaj kolejke z pliku." << std::endl; 
        std::cout << "8. Wygeneruj losowe dane." << std::endl; 
        std::cout << "9. Powrot do menu glownego." << std::endl;
        std::cout << "Wybierz: ";
        std::cin >> operationMenu;
        switch (operationMenu) {
            case 1: {
                std::cout << "Podaj wartosc elementu: ";
                std::cin >> element;
                std::cout << "Podaj priorytet elementu: ";
                std::cin >> priority;
                pq.insert(element, priority);
                std::cout << "Element został dodany.";
                break;
            }
            case 2: {
                PriorityQueue::Node node;
                try {
                    node = pq.extractMax();
                } catch (const std::runtime_error& e) {
                    std::cerr << "Blad: " << e.what() << std::endl;
                    break;
                }
                std::cout << "Pobrano najwiekszy element: " << node.element << " o priorytecie " << node.priority;
                break;
            }
            case 3: {
                PriorityQueue::Node node;
                try {
                    node = pq.peek();
                } catch (const std::runtime_error& e) {
                    std::cerr << "Blad: " << e.what() << std::endl;
                    break;
                }
                std::cout << "Najwiekszy element: " << node.element << " o priorytecie: " << node.element;
                break;
            }
            case 4: {
                std::cout << "Podaj wartosc elementu: ";
                std::cin >> element;
                std::cout << "Podaj nowy priorytet elementu: ";
                std::cin >> priority;
                pq.modifyKey(element, priority);
                std::cout << "Element został dodany.";
                break;
            }
            case 5: {
                std::cout << "Rozmiar kolejki: " << pq.getSize();
                break;
            }
            case 6: {
                std::string filename;
                std::cout << "Podaj nazwe pliku w ktorym chcesz zapisac kolejke: ";
                std::cin >> filename;
                saveContainerToFile(pq, filename);
                break;
            }
            case 7: {
                std::string filename;
                std::cout << "Plik powinien znajdowac sie w folderze data." << std::endl;
                std::cout << "Podaj nazwe pliku ktory chcesz wczytac do kolejki: ";
                std::cin >> filename;
                loadFileToContainer(pq, filename);
                break;
            }
            case 8: {
                int seed = rand();
                int amountOfData;
                std::cout << "Podaj ile danych chcesz wygenerowac: ";
                std::cin >> amountOfData;
                fillContainerWithRandomData(pq, amountOfData, seed);
                break;
            }
            case 9: 
                return;
            case 10: 
                std::cout << "Niepoprawny wybor opcji menu." << std::endl;
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    while (true) {
        int structureMenu;
        std::cout << std::endl << "Wybierz rodzaj implementacji kolejki priorytetowej:" << std::endl;
        std::cout << "1. Kolejka w oparciu o tablice" << std::endl;
        std::cout << "2. Kolejka w opraciu o kopiec" << std::endl;
        std::cout << "3. Wykonaj pomiary dla wszystkich implementacji kolejki" << std::endl;
        std::cout << "4. Wyjdz z programu" << std::endl;
        std::cout << "Wybierz: ";
        std::cin >> structureMenu;
        switch (structureMenu) {
            case 1: {
                // PQArrayMax pqArray;
                // performOperations(pqArray);
                break;
            }
            case 2: {
                PQHeapMax pqHeap;
                performOperations(pqHeap);
                break;
            }
            case 3: {
                // Tablica ziaren oraz inicjalizacja
                int seeds[20]; 
                for (int i = 0; i < 20; i++) {
                    seeds[i] = rand();
                }
                // Tablica elementow oraz priorytetow ktore sa wykorzystane podczas uzycia funkcji insert i modifyKey, generowane losowo
                uint32_t element[5]; 
                uint32_t priority[5];
                for (int i = 0; i < 5; i++) {
                    std::mt19937 gen(seeds[i]);
                    element[i] = generateRandomNumberFromSeed(gen);
                    priority[i] =  generateRandomNumberFromSeed(gen);
                    std::cout << std::endl << i+1 << ". Seed: " << seeds[i] << std::endl << "element dodawany/modyfikowany: "  << element[i] << "," << std::endl << "priorytet: " << priority[i] << std::endl;
                }
                // Punkty pomiarowe - zestawy danych o roznej wielkosci do pomiaru. Dla kazdego seedu 9 roznych wielkosci danych
                int dataSetSize[10] = {8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000, 2048000, 4096000};
                measureAndSave("HEAP_INSERT", HEAPMAX, INSERT, 10, dataSetSize, 20, seeds, 100, element, priority);
                measureAndSave("HEAP_EXTRACTMAX", HEAPMAX, EXTRACT_MAX, 10, dataSetSize, 20, seeds, 100, element, priority);
                measureAndSave("HEAP_PEEK", HEAPMAX, PEEK, 10, dataSetSize, 20, seeds, 100, element, priority);
                measureAndSave("HEAP_MODIFYKEY", HEAPMAX, MODIFY_KEY, 10, dataSetSize, 20, seeds, 100, element, priority);
                measureAndSave("HEAP_RETURNSIZE", HEAPMAX, RETURN_SIZE, 10, dataSetSize, 20, seeds, 100, element, priority);
                std::cout << "Pomiary zostaly wykonane i zapisane w pliku.";
                break;
            }
            case 4: 
                return 0;
            default:
                std::cout << "Niepoprawny wybor opcji menu." << std::endl;
                break;
        }
    }
}
