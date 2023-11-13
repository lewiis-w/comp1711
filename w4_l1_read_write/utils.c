#include "utils.h"
//"" are used for utils.h instead of <> as it tells c where to 
//look (<> is for the system dir)
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}