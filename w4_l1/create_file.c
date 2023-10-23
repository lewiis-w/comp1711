#include <stdio.h>

int main() {
    char filename [] = "data_cf.txt";
    FILE *file = fopen(filename, "w"); //or "a", "w+", "a+" (google later)
    //this is just an check that the operations above were successful and giving an error if not
    if (file == NULL) {
        perror("");
        return 1;
    }

    fclose(file);
    return 0;
}