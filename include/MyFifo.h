#ifndef __HELLO_H__
#define __HELLO_H__

#define MAX_SIZE 50

#define INIT_ERROR 1
#define MAX_MEMORY_REACH 2
#define EMPTY_FIFO 3

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
