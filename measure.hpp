#include "headers/Timer.hpp"
#include <iostream>
enum Function {
    INSERT,
    EXTRACT_MAX,
    PEEK,
    MODIFY_KEY,
    RETURN_SIZE    
};

template<typename T>
double measure(T container, Function func, int32_t number = 0, int priority = 0) { 
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
double measureAverage(T container, Function func, int repetitions, int32_t number = 0, int priority = 0) {
    double avg;
    int sum = 0;
    for (int i = 0; i < repetitions; i++) {
        sum += measure(container, func, number, priority);
    }
    avg = sum / repetitions;
    return avg;
};