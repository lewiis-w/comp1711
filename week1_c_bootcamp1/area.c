#include <stdio.h>
int main () {
    float length;
    float width;
    float area; 

    printf("enter side 1 value: ");
    scanf("%f", &length);
    printf("enter side 2 value: ");
    scanf("%f", &width);

    area = length * width;
    
    printf("the area is %f\n", area);


    return 0;


}