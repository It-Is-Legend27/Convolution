#include <stdio.h>
#include <stdlib.h>
#define M 4096
#define N 1024

int main()
{
    // Create (if does not exist) and open file for write
    FILE* outputFilePtr = fopen("AngelBadilloA5.csv", "w");
    
    // Create arrays
    int F[M];
    int G[N];
    int H[N+M-2];


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
    
    

    fclose(outputFilePtr);
}