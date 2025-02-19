#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int sum = 0;
    int num = 0;

    // Prompt the user to enter the filename
    printf("Enter the filename: ");
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
        if (isdigit(ch)) {
            // If the character is a digit, build the number
            num = num * 10 + (ch - '0');
        } else {
            // If the character is not a digit, add the number to the sum
            sum += num;
            num = 0; // Reset the number for the next sequence of digits
        }
    }

    // Add the last number in the file to the sum
    sum += num;

    // Close the file
    fclose(file);

    // Print the sum of the numbers
    printf("The sum of all numbers in the file is: %d\n", sum);

    return 0;
}