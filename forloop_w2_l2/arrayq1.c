#include <stdio.h>

int main() {
    char str[] =="hello";
    int length = 0;

    //manually determine length of string
    while (str[length] != '\0') {
        length++;
    }

    //print 
}   for (int i = length; i >= 0; i--) {
    if (str[i] == '\0') {
        printf("\\0 ");
    } else {
        printf("%c ", str[i]);
    }
}

printf("\n");

return 0:
//unfinished (debug)