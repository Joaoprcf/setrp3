#ifndef __HELLO_H__
#define __HELLO_H__

#define MAX_SIZE 50

#define NO_ERROR 0
#define INIT_ERROR 0b1
#define MAX_MEMORY_REACH 0b10
#define EMPTY_FIFO 0b100

typedef unsigned int uint;

typedef struct MyFifo
{
  
        uint max_size;
        uint occupyied;
        uint tail;
        uint head;
        int vect[MAX_SIZE];
       
} MyFifo;

int MyFifoInit(MyFifo * fifo, uint size);
int MyFifoInsert(MyFifo * fifo, int value);
int MyFifoRemove(MyFifo * fifo);
int MyFifoPeep(MyFifo * fifo, int * value);
uint MyFifoSize(MyFifo * fifo);

#endif
