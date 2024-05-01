#include <iostream>
#include "headers/PQHeapMax.hpp"
#include "headers/measure.hpp"

int main() {
    PQHeapMax h1;
    for(int i = 0; i < 100000; i++) {
        h1.insert(i, 5);
    }
}