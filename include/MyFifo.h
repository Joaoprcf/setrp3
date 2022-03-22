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

/**
 * @brief MyFifo structure
 * 
 */
typedef struct MyFifo
{

        uint max_size; /**< Max size of fifo */
        uint occupyied; /**< Number of elements */
        uint tail; /**< index of the tail */
        uint head; /**< index of the head */
        int vect[MAX_SIZE]; /**< array of the elements */

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
