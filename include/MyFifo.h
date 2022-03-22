#ifndef __HELLO_H__
#define __HELLO_H__

#define MAX_SIZE 50

#define INIT_ERROR 1

typedef unsigned int uint;

class MyFifo
{
    private:
        int max_size;
        int occupyied;
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
