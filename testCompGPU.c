#include <stdio.h>      
#include <complex.h> 
#include "timer.h"
#define SIZE_N 4096
#define SIZE_M 4096


int main() {
    
    double complex a[SIZE_N][SIZE_M]; 
    double complex b[SIZE_N ][SIZE_M];
    double complex sumAr[SIZE_N ][SIZE_M]; 
	
	   
	
	StartTimer();
	
	#pragma acc data copyin(a,b) copyout(sumAr)
	{
        #pragma acc parallel loop independent
          for( int i = 0; i<SIZE_M; i++){
				for(int j = 0 ; j<SIZE_N; j++){	
					a[i][j] = i+j;
					b[i][j] = (i+j)*I;
            //printf(" complex b[%d]= %.2f %+.2fi\n", i, creal(b[i]), cimag(b[i]) );
            //printf(" complex b[%d][%d]= %.2f %+.2fi", i,j,b[i][j] , b[i][j] );
				}
        //printf("\n");
			}
		
	
        #pragma acc parallel loop independent
			for( int i = 0; i<SIZE_M; i++){
				for(int j = 0 ; j<SIZE_N; j++){
					sumAr[i][j] = a[i][j] + b[i][j];
            //printf("%.2f + %.2fi   ", sumAr[i][j]);
				}
         //printf("\n");
			}
			
	}

		
	
	double runtime = GetTimer();
	printf("totalGPU: %f s\n", runtime / 1000.f);
    

    

    return 0;
}
