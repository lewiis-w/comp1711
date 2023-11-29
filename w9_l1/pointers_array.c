#include <stdio.h>

int main()
{
    int vector[5] = {1,2,3,4,5};

    int* address;

    address = vector;
    // because the vector is not a single var but just an address there is no need 
    // for the "&" before it 

    printf("\n \n address = %p\n", address);

    printf( " vector = %p\n\n",vector);

    printf ("address[0] = %d  ,  vector[0] = %d  \n\n",address[0],vector[0]);
    // the [] simply represent the offset from the array so anything pointing to the memory
    // location can use them to display values in the array
}