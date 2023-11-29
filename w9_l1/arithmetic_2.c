#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17,23,31};

    int* address = vector;

    printf ("\nAddress[0] = %d\n", *address);

    printf ("\nAddress[1] = %d\n", *address++);

    printf ("\nAddress[2] = %d\n", *++address);

    printf ("\nWhat is happening here?\n\n");

    // the placement of the ++ decides when the incriment happens so the 2nd print prints "address"
    // then incriments and 3rd print takes the incrimented "address", incriments the "address"
    // again and therefore print the correct value
}