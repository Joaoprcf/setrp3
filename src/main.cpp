#include <stdio.h>
#include "MyFifo.h"

int main(int argc, char *argv[])
{
    MyFifo fifo;
    int error_value = fifo.MyFifoInit(20);
    printf("error_value: %d\n", error_value);


    return 0;
}