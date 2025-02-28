#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    double sum;
    double sum1 = 0.0;
    double sum2 = 0.0;
    double sum3 = 0.0;
    double sum4 = 0.0;
    double sum5 = 0.0;
    double sum6 = 0.0;
    char buffer[100];
    int buffer_index = 0;
    int turn = 0;
    int iteration = 0;

    // Prompt the user to enter the filename
    //printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // If the character is a digit or a decimal point, add it to the buffer
        if (isdigit(ch) || ch == '.') {
            buffer[buffer_index++] = ch;
        } else {
            // If the character is not part of a number, process the buffer
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0'; // Null-terminate the buffer
                switch(turn){
                    case 0:
                        sum1+=atof(buffer);
                        ++turn;
                        break;
                    case 1:
                        sum2+=atof(buffer);
                        sum+=atof(buffer);
                        ++turn;
                        break;
                    case 2:
                        sum3+=atof(buffer);
                        sum+=atof(buffer);
                        ++turn;
                        break;
                    case 3:
                        sum4+=atof(buffer);
                        sum+=atof(buffer);
                        turn++;
                        break;
                    case 4:
                        sum5+=atof(buffer);
                        sum+=atof(buffer);
                        turn++;
                        break;
                    case 5:
                        sum6+=atof(buffer);
                        sum+=atof(buffer);
                        turn++;
                        printf("%.2f\n",sum);
                        sum = 0.0;
                        break;
                    case 6:
                        turn++;
                        break;
                    case 7:
                        turn = 0;
                        break;
                }// Convert the buffer to a double and add to the sum
                buffer_index = 0;            // Reset the buffer index
            }
        }
    }

    // Process the last number in the file (if any)
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        sum+=atof(buffer);
        printf("%.2f\n",sum);
        switch(turn){
            case 0:
                sum1+=atof(buffer);
                ++turn;
                break;
            case 1:
                sum2+=atof(buffer);
                ++turn;
                break;
            case 2:
                sum3+=atof(buffer);
                ++turn;
                break;
            case 3:
                sum4+=atof(buffer);
                turn=0;
                sum+=atof(buffer);
                printf(".%2f\n",sum);
                break;
        }// Convert the buffer to a double and add to the sum
    }

    // Close the file
    fclose(file);

    // Print the sum of the numbers
    // printf("1st: %.2f 2nd: %.2f 3rd: %.2f 4th: %.2f 5th: %.2f 6th: %.2f\n", sum1/100, sum2/100, sum3/100, sum4/100, sum5/100, sum6/100);
    // sum = sum1+sum2+sum3+sum4+sum5+sum6;
    // printf("The sum of all numbers in the file is: %.2f\n", sum/100);

    return 0;
}