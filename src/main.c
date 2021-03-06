/**
 * @file main.c
 * @author João Ferreira, João Carvalho e Daniel Oliveira
 * @brief Test file of MyFifo struct and its corresponding functions 
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <assert.h>

#include "MyFifo.h"


int main(int argc, char *argv[])
{
    MyFifo fifo;
    int error_value = MyFifoInit(&fifo, 70);
    assert(error_value == INIT_ERROR);

    error_value = MyFifoInit(&fifo, 3);
    assert(error_value == NO_ERROR); 
    
    error_value = MyFifoInsert(&fifo, 4) | MyFifoInsert(&fifo, 3) | MyFifoInsert(&fifo, 2); // fifo should be [4,3,2]
    assert(error_value == NO_ERROR); 
    
    error_value = MyFifoInsert(&fifo, 5); 
    assert(error_value == MAX_MEMORY_REACH); 

    int return_value;

    return_value = MyFifoSize(&fifo);
    assert(return_value == 3);

    error_value = MyFifoPeep(&fifo, &return_value);
    assert(return_value == 4 && error_value == NO_ERROR);    

    error_value = MyFifoRemove(&fifo); // fifo should be [3,2] after remove
    assert(error_value == NO_ERROR);     

    error_value = MyFifoPeep(&fifo, &return_value);
    assert(return_value == 3 && error_value == NO_ERROR); 

    error_value = MyFifoRemove(&fifo); // fifo should be [2] after remove
    assert(error_value == NO_ERROR);     

    error_value = MyFifoPeep(&fifo, &return_value);
    assert(return_value == 2 && error_value == NO_ERROR); 

    error_value = MyFifoRemove(&fifo); // fifo should be [] after remove
    assert(error_value == NO_ERROR);

    error_value = MyFifoPeep(&fifo, &return_value);
    assert(error_value == EMPTY_FIFO); 

    error_value = MyFifoRemove(&fifo);
    assert(error_value == EMPTY_FIFO);

    return_value = MyFifoSize(&fifo);
    assert(return_value == 0);

    printf("All tests passed.\n");

    return 0;
}