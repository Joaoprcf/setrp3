#include <stdio.h>
#include <cassert>

#include "MyFifo.h"


int main(int argc, char *argv[])
{
    MyFifo fifo;
    int error_value = fifo.MyFifoInit(70);
    assert(error_value == INIT_ERROR);

    error_value = fifo.MyFifoInit(3);
    assert(error_value == NO_ERROR); 
    
    error_value = fifo.MyFifoInsert(4) | fifo.MyFifoInsert(3) | fifo.MyFifoInsert(2); // fifo should be [4,3,2]
    assert(error_value == NO_ERROR); 
    
    error_value = fifo.MyFifoInsert(5); 
    assert(error_value == MAX_MEMORY_REACH); 

    int return_value = fifo.MyFifoPeep();
    assert(return_value == 4);    

    error_value = fifo.MyFifoRemove(); // fifo should be [3,2] after remove
    assert(error_value == NO_ERROR);     

    return_value = fifo.MyFifoPeep();
    assert(return_value == 3); 

    error_value = fifo.MyFifoRemove(); // fifo should be [2] after remove
    assert(error_value == NO_ERROR);     

    return_value = fifo.MyFifoPeep();
    assert(return_value == 2); 

    error_value = fifo.MyFifoRemove(); // fifo should be [] after remove
    assert(error_value == NO_ERROR);

    error_value = fifo.MyFifoRemove();
    assert(error_value == EMPTY_FIFO);

    printf("All tests passed!!\n");

    return 0;
}