//**************************************************************
// This is just to test the sample output
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>

// Number of elements in F
#define M 5

// Number of elements in G
#define N 3

// Number of elements in H
#define O N+M-1

// Size of buffer to hold formatted string
#define STR_SZ 128

// Simple buffer to hold formatted string before printing
// Will be size 128, just to be safe and avoid accessing out
// of bounds.
typedef char string_buffer[STR_SZ];

int main()
{
    // For use to hold formatted string
    string_buffer output_string;
    
    // Create (if does not exist) and open file for write
    FILE* outputFilePtr = fopen("test.csv", "w");
    
    // Create arrays for sequences F, G, and resulting H
    int F[M] = {1,2,3,4,5};
    int G[N] = {5,6,7};
    int H[O] = {0};

    // Checksum to be calculated once H is computed
    int checkSum = 0;

    // Computes all values of H(n) from 0 up to N+M-2
    for (int n = 0; n < O; n++)
    {
        // Compute each part the sum of F(m)*G(n-m), and add it
        // to the total sum in H(n)
        for (int m = 0; m <= n; m++)
        {
            // Only performed if indices are valid.
            // If m < 0 and m >= M and n < 0 and n <= N, this
            // instruction will be skipped as the item to be added to the sum
            // will be 0.
            if(m >= 0 && m < M && (n-m) >= 0 && (n-m) < N)
            H[n] += F[m]*G[n-m];
        }
    }
    
    // Printing number of elements in each array of values
    printf("Number of elements in f: %d\n", M);
    printf("Number of elements in g: %d\n", N);
    printf("Number of elements in h: %d\n", O);

     // Print labels for columns to .csv file
    fputs("H[i], value\n", outputFilePtr);

    // Print every element of H to .csv file
    for (int i = 0; i < O; i++)
    {
        // Create formatted string, store in buffer, output_string
        sprintf(output_string, "H[%d], %d\n", i, H[i]);

        // Print output_string to .csv file
        fputs(output_string, outputFilePtr);
    }
    
    // Close the file
    fclose(outputFilePtr);
}