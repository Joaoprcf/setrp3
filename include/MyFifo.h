#ifndef __HELLO_H__
#define __HELLO_H__

#define MAX_SIZE 50

#define NO_ERROR 0
#define INIT_ERROR 0b1
#define MAX_MEMORY_REACH 0b10
#define EMPTY_FIFO 0b100

typedef unsigned int uint;

class MyFifo
{
    private:
        uint max_size;
        uint occupyied;
        uint tail;
        uint head;
        int vect[MAX_SIZE];

    public:
        int MyFifoInit(uint size);
        int MyFifoInsert(int value);
        int MyFifoRemove();
        int MyFifoPeep();
        uint MyFifoSize();
};

#endif
