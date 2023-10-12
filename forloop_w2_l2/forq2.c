#include <stdio.h>

int main() {
    int a;

    for (a = 20; a > 2; a-=2)
    {
        printf ("a is equal to %d\n", a);
    }
    printf ("I've finished the loop and a is equal to %d\n", a);

    return (0);
}