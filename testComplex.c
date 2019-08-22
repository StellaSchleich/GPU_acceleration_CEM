
#include <stdio.h>      
#include <complex.h> 
#include "timer.h"
#define SIZE_N 4096
#define SIZE_M 4096


int main() {
	
	/*

    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Working with complex numbers:\n\v");

    printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));
    printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n", z1, z2); // dont have to seperately acess real and imag

    double complex sum = z1 + z2;
    printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("The product: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    double complex conjugate = conj(z1);
    printf("The conjugate of Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));
    
    */
    double complex a[SIZE_N][SIZE_M]; 
    double complex b[SIZE_N ][SIZE_M];
    double complex sumAr[SIZE_N ][SIZE_M]; 
   
      
	StartTimer();
    
    for( int i = 0; i<SIZE_M; i++){
        for(int j = 0 ; j<SIZE_N; j++){
            a[i][j] = i+j;
            b[i][j] = (i+j)*I;
            //printf(" complex b[%d]= %.2f %+.2fi\n", i, creal(b[i]), cimag(b[i]) );
            //printf(" complex b[%d][%d]= %.2f %+.2fi", i,j,b[i][j] , b[i][j] );
        }
        //printf("\n");
    }
    
  
    
    for( int i = 0; i<SIZE_M; i++){
        for(int j = 0 ; j<SIZE_N; j++){
            sumAr[i][j] = a[i][j] + b[i][j];
            //printf("%.2f + %.2fi   ", sumAr[i][j]);
        }
         //printf("\n");
    }
	double runtime = GetTimer();
	printf("totalCPU: %f s\n", runtime / 1000.f);
    

    

    return 0;
}
