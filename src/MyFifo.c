#include "MyFifo.h"


int MyFifoInit(MyFifo * fifo, uint size) {
    
    if(size > MAX_SIZE) 
        return INIT_ERROR;

    fifo->head = 0;
    fifo->tail = 0;
    fifo->occupyied = 0;
    fifo->max_size = size;

    return 0;
}

int MyFifoInsert(MyFifo * fifo, int value) {
    
    if(fifo->occupyied >= fifo->max_size) {
        return MAX_MEMORY_REACH;
    }

    fifo->vect[fifo->tail] = value;
    fifo->tail = (fifo->tail+1)%MAX_SIZE;
    fifo->occupyied++;

    return 0;
}

int MyFifoRemove(MyFifo * fifo) {
    
    if(fifo->occupyied <= 0) {
        return EMPTY_FIFO;
    }
    
    fifo->head = (fifo->head+1)%MAX_SIZE;
    fifo->occupyied--;

    return 0;
}

int MyFifoPeep(MyFifo * fifo, int * value) {
    if(fifo->occupyied <= 0) {
        return EMPTY_FIFO;
    }
    *value = fifo->vect[fifo->head]; 
    return NO_ERROR;
}

uint MyFifoSize(MyFifo * fifo) {
    return fifo->occupyied;
}
