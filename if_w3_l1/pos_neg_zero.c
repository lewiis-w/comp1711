#include <stdio.h>

int main() {

    float num;

    printf ("please enter your number ");
    scanf ("%f", &num);

    if (num != 0)
    // != checks if the num is not 0 
    {
        if (num > 0)
        {
            printf("the number you've entered is positive\n");
        }
        else 
        {
            printf("the number you've entered is negative\n");
        }
    }
    else 
    {
        printf ("you have entered zero, which is neither positive or negative\n");
    }
    
    return 0;
}