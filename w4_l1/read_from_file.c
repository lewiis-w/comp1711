#include <stdio.h>
int main() {
    char filename [] = "data_wtf.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }
    //this below is critical for the coursework
    int buffer_size = 100; 
    //buffer size just needs to be big enough to hold the values
    //(going far over is fine)
    char line_buffer[buffer_size];
    //this goes line by line, takes the the 100 or less char,
    //and reads them. Looping until it finds an empty file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }
    //very important to close file before returning
    fclose(file);
    return 0;
}