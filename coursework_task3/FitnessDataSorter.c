#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

int file_counter;

// used the old tokeniser instead as this one was playing up
void tokeniseRecordUnused(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

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

int compare(const void* x_void, const void* y_void) {
    FitnessData* FitnessDatax = (FitnessData*)x_void;
    FitnessData* FitnessDatay = (FitnessData*)y_void;
    return FitnessDatay->steps - FitnessDatax->steps;
}


int main() {


    char filename[60];

     int buffer_size = 50;
     char line_buffer[buffer_size];
    
     FitnessData data1[500];

      printf("Please enter the name of the data file: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            FILE *file = fopen(filename, "r");
                if (!file)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }


            file_counter = 0;
            while (fgets(line_buffer, buffer_size, file) != NULL) {
            //needed for tokenise function to work?
            char date1[11];
            char time1[6];
            char steps1[8];

            tokeniseRecord(line_buffer, ",", date1, time1, steps1);

            if (strlen(date1) != 10 || strlen(time1) != 5) {
                printf("data bad\n");
                fclose(file);
                return 1;
            }

            strcpy(data1[file_counter].date, date1);
            strcpy(data1[file_counter].time, time1);
            data1[file_counter].steps = atoi(steps1);
            if (data1[file_counter].steps == 0) {
                return 1;
            }

            file_counter += 1;
            }

            fclose(file);
            printf("file successfully loaded.\n");

    qsort(data1, file_counter, sizeof(FitnessData), compare);
 
    FILE *File = fopen(strcat(filename, ".tsv"), "w");
    if (!File) {
        return 1;
    }
    for (int i = 0; i < file_counter; i++)
        fprintf(File,"%s\t%s\t%d\n", data1[i].date, data1[i].time, data1[i].steps);

    fclose(File);
    
    return 0;
    
}