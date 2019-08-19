
#include <stdio.h>      
#include <complex.h> 
#include "timer.h"  

int main() {

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
    
    printf(" --------- MATRIX --------- \n");
    double complex a[3] = {1, 2, 3}; 
    double b[3] = {4, 5, 6 };
    double complex complex_b[3];
    
    
    //Making b complex 
    //OR b[3] = {4*I, 5*I, 6*I};
    for( int i = 0; i< 3; i++){
        complex_b[i] = b[i]*I;
        printf(" complex b[%d]= %.2f %+.2fi\n", i, creal(complex_b[i]), cimag(complex_b[i]) );
    }
    
    
    double complex sumAr[3]; 
    for( int i = 0; i < 3; i++){
        sumAr[i] = a[i] + complex_b[i];
        printf("SUM: %.2f + %.2fi \n", sumAr[i]);
    }
    
    

    return 0;
}
