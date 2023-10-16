#include <stdio.h>
int main() {
    int mark;
  printf("please enter your mark:");
  scanf("%d", &mark);

    if (mark == 0)
    {
        printf ("the mark of %d is a zero\n", mark);
    }
    else if (mark > 0 && mark <= 39)
    {
        printf ("the mark of %d is fail\n", mark);
    }
    else if (mark > 39 && mark <=100)
    {
        printf ("the mark of %d is a pass\n", mark);
    }
    else
    {
        printf("please enter a value between 0 and 100\n");
    }
    return 0;
    
}