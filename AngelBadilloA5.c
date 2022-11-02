#include <stdio.h>
#include <stdlib.h>
#define M 4096
#define N 1024
typedef char string_buffer[N];
int main()
{
    string_buffer buffer;
    
    // Create (if does not exist) and open file for write
    FILE* outputFilePtr = fopen("AngelBadilloA5.csv", "w");
    
    // Create arrays
    int F[M];
    int G[N];
    int H[N+M-2] = {0};


    // Init from 1 to 4096
    for (int m = 0; m < M; m++)
    {
        F[m] = m + 1;
    }

    // Init from 1024 down to 1
    for (int n = 0; n < N; n++)
    {
        G[n] = N - n;
    }
    

    for (int n = 0; n <= N+M-2; n++)
    {
        for (int m = 0; m <= n; m++)
        {
            if(m >= 0 && m < M && (n-m) >= 0 && (n-m) < N)
            H[n] += F[m]*G[n-m];
        }
    }
    
    printf("Number of elements in f: %d\n", M);
    printf("Number of elements in g: %d\n", N);
    printf("Number of elements in h: %d\n", N+M-2);

    // Print every element of H to .csv file
    for (int i = 0; i < N+M-1; i++)
    {
        sprintf(buffer, "H[%d] = %d\n", i, H[i]);
        fputs(buffer, outputFilePtr);
    }
    
    fclose(outputFilePtr);
}