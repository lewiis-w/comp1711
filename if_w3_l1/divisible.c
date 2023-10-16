#include <stdio.h> 
 int main() {

    int num;

    printf ("please enter your number to check its divisiblity by both 4 and 5: ");
    scanf ("%d", &num); 

    if (!(num % 4) && !(num % 5))
    {
        printf("congrats your number is divisible by both 4 and 5!\n");
    }
    else 
    {
    printf("sorry your number is not divisble by 4 and 5\n");
    }

    return 0;
}