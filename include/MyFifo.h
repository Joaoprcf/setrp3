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

/**
 * @brief Fuction to initialize struct MyFifo with a size value
 * Possible Erros: INIT_ERROR
 * @param[in] MyFifo struct, Size
 * @param[out] error_value
 */
int MyFifoInit(MyFifo * fifo, uint size);

/**
 * @brief Fuction to Insert value into the vector from the struct MyFifo
 * Possible Erros: INIT_ERROR
 * @param[in] MyFifo struct, Size
 * @param[out] error_value
 */
int MyFifoInsert(MyFifo * fifo, int value);
int MyFifoRemove(MyFifo * fifo);
int MyFifoPeep(MyFifo * fifo, int * value);
uint MyFifoSize(MyFifo * fifo);

#endif
