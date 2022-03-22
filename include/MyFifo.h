/** @file MyFifo.h
 * @brief Fifo implementation with struct and its corresponding functions  

 * 
 * 
 * @author João Ferreira e João Carvalho
 * @date 22 March 2022
 * @bug No known bugs.
 */

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


/**
 * @brief Remove the next element in the queue
 * 
 * 
 * @param[in] fifo 
 * @param[out] value 
 * @return uint 
 */

int MyFifoRemove(MyFifo * fifo);

/**
 * @brief Look at the next element in the queue
 * 
 * 
 * @param[in] fifo 
 * @param[out] value 
 * @return uint 
 */
int MyFifoPeep(MyFifo * fifo, int * value);

/**
 * @brief Get the number of elements in the queue 
 * 
 * 
 * @param[in] fifo 
 * @return uint 
 */

uint MyFifoSize(MyFifo * fifo);

#endif
