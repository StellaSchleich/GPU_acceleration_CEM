#include <stdio.h>
#include <math.h>
#include "timer.h"
#define SIZE 10

int main()
{
    
    int a[SIZE][SIZE];
	int b[SIZE][SIZE];
	int c[SIZE][SIZE];
	

	int i,j;
	for( i = 0; i < SIZE ; i++){
		for(j = 0 ; j < SIZE; j++){
		    a[i][j] = j;
            b[i][j] = j;
		}
	}
	
   
	StartTimer();
	#pragma acc parallel loop collapse(2)
		for( int i = 0; i < SIZE ; i++){
			for(int j = 0 ; j < SIZE; j++){
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		

    double runtime = GetTimer();
	printf("C[0][0] = %d\n", c[0][0]);
	printf("C[0][1] = %d\n", c[0][1]);
	printf("totalGPU: %f s\n", runtime / 1000.f);
	
	
   return 0;
}
