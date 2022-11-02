// Angel Badillo and James
#include <stdio.h>
#include <stdlib.h>

// Number of elements in F
#define M 4096

// Number of elements in G
#define N 1024

// Simple buffer to hold formatted string before printing
typedef char string_buffer[N];

int main()
{
    // For use to hold formatted string
    string_buffer output_string;
    
    // Create (if does not exist) and open file for write
    FILE* outputFilePtr = fopen("AngelBadilloA5.csv", "w");
    
    // Create arrays
    int F[M];
    int G[N];
    int H[N+M-2] = {0};

    // Initialize F starting from 1 up to 4096
    for (int m = 0; m < M; m++)
    {
        F[m] = m + 1;
    }

    // Initialize G from 1024 down to 1
    for (int n = 0; n < N; n++)
    {
        G[n] = N - n;
    }

    // Computes all values of H(n) from 0 up to N+M-2
    for (int n = 0; n <= N+M-2; n++)
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
    printf("Number of elements in h: %d\n", N+M-2);

    // Print every element of H to .csv file
    for (int i = 0; i <= N+M-1; i++)
    {
        // Create formatted string, store in buffer, output_string
        sprintf(output_string, "H[%d] = %d\n", i, H[i]);

        // Print output_string to .csv file
        fputs(output_string, outputFilePtr);
    }
    
    // Close the file
    fclose(outputFilePtr);
}