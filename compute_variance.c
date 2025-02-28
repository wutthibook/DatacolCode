#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file;
    char filename[100];
    double number, sum = 0.0, mean = 0.0, variance = 0.0;
    int count = 0;

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

    // Read numbers line by line and compute the sum
    while (fscanf(file, "%lf", &number) == 1) {
        sum += number;
        count++;
    }

    // Check if the file contains at least one number
    if (count == 0) {
        printf("The file contains no numbers.\n");
        fclose(file);
        return 1;
    }

    // Compute the mean
    mean = sum / count;

    // Reset the file pointer to the beginning of the file
    rewind(file);

    // Compute the variance
    while (fscanf(file, "%lf", &number) == 1) {
        variance += pow(number - mean, 2);
    }

    // Divide by the number of elements to get the variance
    variance /= count;

    // Close the file
    fclose(file);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Total data count: %d\n", count);

    return 0;
}