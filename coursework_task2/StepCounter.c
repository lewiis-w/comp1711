#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
int file_counter = 0;
int counter = 0;
char filename[60];
char inputchar;
// variables for C
int lowest_steps;
int lowest_steps_index;
// variables for D
int highest_steps;
int highest_steps_index;
// variables for E
int sum;
float floatsum;
float floatmean;
float floatmeanrounded;
int intmean;
// variables for F
int record_counter;
int record;
int counter_index;
int endindexrecord;


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

int main() {

     int buffer_size = 50;
     char line_buffer[buffer_size];
    
     FITNESS_DATA data1[500];

   while (1) {
        printf("A: \n");
        printf("B: \n");
        printf("C: \n");
        printf("D: \n");
        printf("E: \n");
        printf("F: \n");
        printf("Q: \n");

        inputchar = getchar();

        while (getchar() != '\n');
            // switch statement to control the menu.
        switch (inputchar)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':


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
            strcpy(data1[file_counter].date, date1);
            strcpy(data1[file_counter].time, time1);
            data1[file_counter].steps = atoi(steps1);
            file_counter += 1;
            }

            fclose(file);
            printf("file successfully loaded.\n");
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", file_counter);
            break;
        case 'C':
        case 'c':
            lowest_steps = 9999;  // very large value
            lowest_steps_index = -1;  // invalid index

            // find the time with the lowest step count
            for (int i = 0; i < file_counter; i++) {
                if (data1[i].steps < lowest_steps) {
                    lowest_steps = data1[i].steps;
                    lowest_steps_index = i;
                }
            }
            printf("Fewest steps: %s %s\n", data1[lowest_steps_index].date, data1[lowest_steps_index].time);
            break;

        case 'D':
        case 'd':
            highest_steps = -1;  // smallest value
            highest_steps_index = -1;  // invalid index

            // find the time with the highest step count
            for (int i = 0; i < file_counter; i++) {
                if (data1[i].steps > highest_steps) {
                    highest_steps = data1[i].steps;
                    highest_steps_index = i;
                }
            }
            printf("Largest steps: %s %s\n", data1[highest_steps_index].date, data1[highest_steps_index].time);
            break;

        case 'E':
        case 'e':
            sum = 0;

            for (int i = 0; i < file_counter; i++) {
                sum += data1[i].steps;
            }

            floatsum = (float)sum;
            floatmean = floatsum / file_counter;
            floatmeanrounded = round(floatmean);
            intmean = (int)floatmeanrounded;
            
            printf("Mean step count: %d\n", intmean);

            break;

        case 'F':
        case 'f':
            record_counter = 0;
            counter_index = -1;
            record = 0 ;
            endindexrecord = -1;

            for (int i = 0; i < file_counter; i++) {
                if (data1[i].steps > 499) {
                    record_counter += 1;
                    counter_index = i;
                }
                else {
                    if (record_counter != 0 && record < record_counter) {
                        record = record_counter;
                        endindexrecord = counter_index;
                        record_counter = 0;
                    }
                    else {
                        record_counter = 0;
                    }
                }
            }
            
            printf("Longest period start: %s %s\n", data1[endindexrecord+1-record].date, data1[endindexrecord+1-record].time);
            printf("Longest period end: %s %s\n", data1[endindexrecord].date, data1[endindexrecord].time);

            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Please enter a valid Input\n");
            break;
   }
   }
}









