#include <stdio.h>
#include <math.h>
#include "timer.h"

int main()
{	int a[100000];
	int b[100000];
	int c[100000];
	
	for( int i = 0; i < 100000 ; i++){
		a[i] = i;
		b[i] = i;
	}

	
	
	StartTimer();
	#pragma acc parallel loop
		for( int i = 0; i < 50000 ; i++){
			for(int j = 0 ; j < 50000; j++){
				c[i+j] = a[i+j] + b[i+j];
			}
		}
   
	double runtime = GetTimer();
	printf("C[100] = %d\n", c[99998]);
    printf("totalGPU: %f s\n", runtime / 1000.f);
   
   return 0;
}
