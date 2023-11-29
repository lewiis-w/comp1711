#include <stdio.h>

int main() {
    int y = 40678;
    int* address = &y;
    printf("\nAddress = %d\n", *address);
}