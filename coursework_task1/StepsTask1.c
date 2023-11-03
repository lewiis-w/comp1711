#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//reformated to all char for consistant code between fields
//nvm it messed with formatting in printf
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// file_counter serves dual purpose of telling strcpy what line in array to print to
// and of being a final count of the files in record
int file_counter = 0;


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");

    int buffer_size = 50;
    char line_buffer[buffer_size];
    
    FITNESS_DATA data1[500];

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        //needed for tokenise function to work?
        char date1[11];
        char time1[6];
        char steps1[8];

        tokeniseRecord(line_buffer, ",", date1, time1, steps1);
        strcpy(data1[file_counter].date, date1);
        strcpy(data1[file_counter].time, time1);
        data1[file_counter].steps = atoi(steps1);
        file_counter += 1;
    }
    fclose(file);

    printf("Number of records in file: %d\n", file_counter);
    printf("%s/%s/%d\n", data1[0].date, data1[0].time, data1[0].steps);
    printf("%s/%s/%d\n", data1[1].date, data1[1].time, data1[1].steps);
    printf("%s/%s/%d\n", data1[2].date, data1[2].time, data1[2].steps);

    return 0;
}
