#include <stdio.h>
#include <stdlib.h>

/*  Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
    The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
    shows the first 11 ugly numbers. By convention, 1 is included.
    Write a program to find and print the i-th ugly number. */

/* Function to find minimum of 3 numbers */
unsigned min(unsigned a, unsigned b, unsigned c) {
    if(a <= b) {
      if(a <= c) return a;
      else return c;
    }

    if(b <= c) return b;
    else return c;
}

/* Function to get the nth ugly number*/
unsigned getUgly(unsigned n) {
    unsigned *ugly = (unsigned *) (malloc (sizeof(unsigned)*n));
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned mul2 = 2;  /* Next multiple of 2 */
    unsigned mul3 = 3;
    unsigned mul5 = 5;
    unsigned nextUgly = 1;

    *(ugly+0) = 1;

    for(int i = 1; i < n; i++) {
       nextUgly = min(mul2, mul3, mul5);
       *(ugly+i) = nextUgly;

       if(nextUgly == mul2) {
           i2 = i2 + 1;
           mul2 = *(ugly + i2)*2;
       }

       if(nextUgly == mul3) {
           i3 = i3 + 1;
           mul3 = *(ugly + i3)*3;
       }

       if(nextUgly == mul5) {
           i5 = i5 + 1;
           mul5 = *(ugly + i5)*5;
       }
    }

    return nextUgly;
}

int main() {
    printf("%d\n", getUgly(10));
    return 0;
}
