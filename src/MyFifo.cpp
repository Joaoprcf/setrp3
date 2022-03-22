#include <iostream>
#include "MyFifo.h"

using namespace std;


int MyFifo::MyFifoInit(uint size) {
    
    if(size > MAX_SIZE) 
        return INIT_ERROR;

    head = 0;
    tail = 0;
    occupyied = 0;
    max_size = size;

    return 0;
}

int MyFifo::MyFifoInsert(int value) {
    
    if(occupyied >= max_size) {
        return MAX_MEMORY_REACH;
    }

    vect[tail] = value;
    tail = (tail+1)%MAX_SIZE;
    occupyied++;

    return 0;
}

int MyFifo::MyFifoRemove() {
    
    if(occupyied <= 0) {
        return EMPTY_FIFO;
    }
    
    head = (head+1)%MAX_SIZE;
    occupyied--;

    return 0;
}

int MyFifo::MyFifoPeep() {
    if(occupyied <= 0) {
        return EMPTY_FIFO;
    }
    
    return vect[head];
}

uint MyFifo::MyFifoSize() {
    return occupyied;
}
